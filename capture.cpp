#include <iostream>

#include "capture.hpp"

/*!
 *
 */
Camera::Camera():
pos(cv::Vec3f(0.0f, 0.0f, 0.0f)),hViewAngle(BUFFALO_BSW13K05H::ANGLE_OF_VIEW_H),vViewAngle(BUFFALO_BSW13K05H::ANGLE_OF_VIEW_V),
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
    crrntPos.resize(MARKER_IDX_NUM);
    prvPos.resize(MARKER_IDX_NUM);
    crrntPosL.reserve(MARKER_IDX_NUM);
    prvPosL.resize(MARKER_IDX_NUM);
    crrntPosR.reserve(MARKER_IDX_NUM);
    prvPosR.resize(MARKER_IDX_NUM);
}

/*!
 *
 */
Marker::~Marker()
{
}

/*!
 *  \param idx マーカのラベルの添字
 *  \param pos マウスでクリックした座標
 */
void Marker::setOneMarkerLabel(int idx, cv::Point2i pos, std::vector<cv::Point2f> &crrnt, std::vector<cv::Point2f> &prv)
{
    float min = FLT_MAX;
    int _idx;

    for (size_t i = 0; i < crrnt.size(); i++)
    {
        //std::cout << "  " << crrnt[i].x << ", " << crrnt[i].y << std::endl;
        //std::cout << "    " << distance(crrnt[i], pos) << std::endl;

        if (min > distance(crrnt[i], pos))
        {
            min = distance(crrnt[i], pos);
            _idx = i;
        }
    }

    prv[idx] = crrnt[_idx];
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
    setMarkerLabel(prvPosL, crrntPosL);
    setMarkerLabel(prvPosR, crrntPosR);

    // マーカ座標の計算
    imRows = camL.srcIm.rows;
    imCols = camL.srcIm.cols;
    getPos3D();
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
    cv::medianBlur(grayIm, medianIm, 3);

    // 閾値処理
    cv::Mat thIm;
    cv::threshold(medianIm, thIm, 225, 255, cv::THRESH_BINARY);

    // マスク処理
    cv::Mat fusionIm;
    srcIm.copyTo(fusionIm, thIm);
    
    // ラベリング
    cv::Mat lblIm = cv::Mat(thIm.size(), thIm.type());
    LabelingBS lblBS;
    short *dst = new short[thIm.rows * thIm.cols];
    lblBS.Exec((uchar *)thIm.data, dst, thIm.cols, thIm.rows, false, 10);
    
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
    pos.clear();
    pos.reserve(lblBS.GetNumOfResultRegions());
    for (int i = 0; i < lblBS.GetNumOfResultRegions(); i++)
    {
        cv::Point2f c;
        RegionInfoBS *ri = lblBS.GetResultRegionInfo(i);

        if (ri->GetNumOfPixels() > 103)
        {
            continue;
        }

        ri->GetCenterOfGravity(c.x, c.y);
        pos.push_back(c);

        cv::circle(centerIm, c, 5, cv::Scalar(255, 255, 255), -1);
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
 *
 */
void Marker::getPos3D()
{
    std::cout << "getPos3D" << std::endl;

    std::cout << "POS: ";
    std::cout << crrntPosL[0].x << ", " << crrntPosL[0].y << " - " << crrntPosR[0].x << ", " << crrntPosR[0].y << std::endl;
    std::cout << "ANG: ";
    std::cout << rad2deg(M_PI-pos2radH(crrntPosL[0].x)) << ", " << rad2deg(pos2radV(crrntPosL[0].y)) << " - " << rad2deg(pos2radH(crrntPosR[0].x)) << ", " << rad2deg(pos2radV(crrntPosR[0].y)) << std::endl;

    for (size_t i = 0; i < crrntPos.size(); i++)
    {
        crrntPos[i] = triangulation(M_PI-pos2radH(crrntPosL[i].x), pos2radV(crrntPosL[i].y), pos2radH(crrntPosR[i].x));
    }
}

/*!
 *  \param prv   ラベルづけされたマーカ座標
 *  \param crrnt 画像から取得したマーカ座標
 */
void Marker::setMarkerLabel(std::vector<cv::Point2f> &prv, std::vector<cv::Point2f> &crrnt)
{
    std::vector<cv::Point2f> pos(prv.size(), cv::Point2f(0.0f, 0.0f));

    for (size_t i = 0; i < prv.size(); i++)
    {
        float min = FLT_MAX;
        int idx;
        for (size_t j = 0; j < crrnt.size(); j++)
        {
            if (min > distance(crrnt[j], prv[i]))
            {
                min = distance(crrnt[j], prv[i]);
                idx = j;
            }
        }
        pos[i] = crrnt[idx];
    }

    // 隠れてしまっても諦めない



    crrnt = pos;
    prv = crrnt;

    //crrnt.swap(pos);
    //pos.swap(prv);
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

    float Xc = sdAC * cos(angLh);
    float Zc = sdAC * sin(angLh);
    float Yc = (sin(angLv)/sin(angCv)) * Zc;

    //std::cout << "----" << std::endl;
    //std::cout << "angLh = " << rad2deg(angLh) << std::endl;
    //std::cout << "angLv = " << rad2deg(angLv) << std::endl;
    //std::cout << "angRh = " << rad2deg(angRh) << std::endl;
    //std::cout << "angCh = " << rad2deg(angCh) << std::endl;
    //std::cout << "angCv = " << rad2deg(angCv) << std::endl;

    //std::cout << "sdAC  = " << sdAC << std::endl;

    return cv::Vec3f(Xc, Yc, Zc);
}

MARKER_IDX getMarkerIdx(cv::Point2i pos)
{

}