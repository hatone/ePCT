#include <iostream>

#include "capture.hpp"

/*!
 *
 */
Camera::Camera():
pos(cv::Vec3f(0.0f, 0.0f, 0.0f)),hViewAngle(BUFFALO_BSW13K05H::HORIZONTAL_ANGLE_OF_VIEW),vViewAngle(BUFFALO_BSW13K05H::VERTICAL_ANGLE_OF_VIEW),
cameraMatrix(cv::Mat(3, 3, CV_64FC1)),distCorffs(cv::Mat(4, 1, CV_64FC1))
{
}

/*!
 *
 */
Camera::~Camera()
{
}

/*!
 *
 */
void Camera::setUndistortParam()
{
    cameraMatrix.at<double>(0, 0) = BUFFALO_BSW13K05H::FOCUS_LEN_X;
    cameraMatrix.at<double>(0, 1) = 0.0;
    cameraMatrix.at<double>(0, 2) = BUFFALO_BSW13K05H::PRINCIPAL_X;

    cameraMatrix.at<double>(1, 0) = 0.0;
    cameraMatrix.at<double>(1, 1) = BUFFALO_BSW13K05H::FOCUS_LEN_Y;
    cameraMatrix.at<double>(1, 2) = BUFFALO_BSW13K05H::PRINCIPAL_Y;

    cameraMatrix.at<double>(2, 0) = 0.0;
    cameraMatrix.at<double>(2, 1) = 0.0;
    cameraMatrix.at<double>(2, 2) = 1.0;

    distCorffs.at<double>(0, 0) = BUFFALO_BSW13K05H::DIST1;
    distCorffs.at<double>(1, 0) = BUFFALO_BSW13K05H::DIST2;
    distCorffs.at<double>(2, 0) = BUFFALO_BSW13K05H::DIST3;
    distCorffs.at<double>(3, 0) = BUFFALO_BSW13K05H::DIST4;
}

/*!
 *
 */
Marker::Marker():
baseLen(BUFFALO_BSW13K05H::DISTANCE)
{
}

/*!
 *
 */
Marker::~Marker()
{
}

/*!
 *  三角測量でcrrntPosにマーカ座標を計算する．
 *  \param camL 左のカメラ
 *  \param camR 右のカメラ
 */
void Marker::calcPos(Camera &camL, Camera &camR)
{
    // 入力画像からマーカの検出
    getPos2D(camL.srcIm, camL.dstIm, crrntPosL);
    getPos2D(camR.srcIm, camR.dstIm, crrntPosR);

    // マーカのラベル付け

    // マーカ座標の計算
    crrntPos.push_back(triangulation(M_PI/3.0f, M_PI/6.0f, M_PI/3.0f));
}

/*!
 *  \param カメラで取得した画像
 */
void Marker::getPos2D(cv::Mat &srcIm, cv::Mat &dstIm, std::vector<cv::Point2f> &pos)
{
    cv::Mat grayIm = cv::Mat(srcIm.size(), CV_LOAD_IMAGE_GRAYSCALE);
    cv::cvtColor(srcIm, grayIm, CV_BGR2GRAY);

    // ノイズ除去
    cv::Mat medianIm;
    cv::medianBlur(grayIm, medianIm, 9);

    // 閾値処理
    cv::Mat thIm;
    cv::threshold(medianIm, thIm, 128, 255, cv::THRESH_BINARY);

    // マスク処理
    cv::Mat fusionIm;
    srcIm.copyTo(fusionIm, thIm);
    
    // ラベリング
    cv::Mat lblIm = cv::Mat(thIm.size(), thIm.type());
    LabelingBS lblBS;
    short *dst = new short[thIm.rows * thIm.cols];
    lblBS.Exec((uchar *)thIm.data, dst, thIm.cols, thIm.rows, false, 1000000);
    
    for (int i = 0; i < thIm.rows*thIm.cols; i++)
    {
        if (dst[i] != 0)
        {
            lblIm.data[i] = 255.0f / (float)dst[i];
        }
        else
        {
            lblIm.data[i] = 0;
        }
    }

    // マーカ候補の重心を求める
    cv::Mat centerIm = fusionIm;
    pos.reserve(lblBS.GetNumOfResultRegions());
    for (int i = 0; i < lblBS.GetNumOfResultRegions(); i++)
    {
        cv::Point2f c;
        RegionInfoBS *ri = lblBS.GetResultRegionInfo(i);

        if (ri->GetNumOfPixels() < 103)
        {
            continue;
        }

        ri->GetCenterOfGravity(c.x, c.y);
        pos.push_back(c);

        cv::circle(centerIm, c, 5, cv::Scalar(255, 0, 0), -1);
    }

    centerIm.copyTo(dstIm);
    

    // 出力
    //cv::namedWindow("cap");
    //cv::imshow("cap", srcIm);
    //cv::namedWindow("median");
    //cv::imshow("median", medianIm);
    //cv::namedWindow("gray");
    //cv::imshow("gray", grayIm);
    //cv::namedWindow("threshhold");
    //cv::imshow("threshhold", thIm);
    //cv::namedWindow("fusion");
    //cv::imshow("fusion", fusionIm);
    //cv::namedWindow("lbl");
    //cv::imshow("lbl", lblIm);
    //cv::namedWindow("center");
    //cv::imshow("center", centerIm);

    //cv::waitKey();
}

/*!
 *  \param A 底辺左端の座標
 *  \param B 底辺右端の座標
 *  \param baseLen 底辺の長さ
 */
cv::Vec3f Marker::triangulation(float angLh, float angLv, float angRh)
{
    float angCh = M_PI - (angLh+angRh);
    float angCv = M_PI_2 - angLv;
    float sdAC = (sin(angRh)/sin(angCh)) * baseLen;

    float Xc = sdAC * sin(angLh);
    float Zc = sdAC * cos(angLh);
    float Yc = (sin(angLv)/sin(angCv)) * Zc;

    return cv::Vec3f(Xc, Yc, Zc);
}
