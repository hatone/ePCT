#include <iostream>
#include <cmath>

#include <mrCV.hpp>

#include "C:\\Users\\Takushi\\git\\ePCT\\capture.hpp"
//#include "capture.hpp"


int main(int argc, char *argv[])
{
    cv::Mat srcIm = cv::imread("cap0.bmp");
    cv::Mat dstIm = cv::Mat(srcIm.size(), srcIm.type());

    Marker mrkr;
    mrkr.getPos2D(srcIm, dstIm, mrkr.crrntPosL);
    std::cout << mrkr.crrntPosL.size() << std::endl;

    for (size_t i = 0; i < mrkr.crrntPosL.size(); i++)
    {
        std::cout << "( " << mrkr.crrntPosL[i].x << " , " << mrkr.crrntPosL[i].y << ")" << std::endl;
    }

    cv::namedWindow("srcIm");
    cv::namedWindow("dstIm");
    cv::imshow("srcIm", srcIm);
    cv::imshow("dstIm", dstIm);

    cv::waitKey();

    return 0;

    //cv::VideoCapture capL(1), capR(2);
    //if (!capL.isOpened())
    //{
    //    return -1;
    //}
    //capL.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    //capL.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    //capR.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    //capR.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    //Camera camL, camR;
    //Marker mrkr;

    //// キャリブレーションの準備
    //camL.setUndistortParam();
    //camR.setUndistortParam();


    //cv::namedWindow("capL");
    //cv::namedWindow("capR");
    //while (true)
    //{
    //    cv::Mat frameLIm, frameRIm;

    //    // キャプチャ
    //    capL >> frameLIm;
    //    capR >> frameRIm;

    //    // キャリブレーション
    //    cv::undistort(frameLIm, camL.srcIm, camL.cameraMatrix, camL.distCorffs);
    //    cv::undistort(frameRIm, camR.srcIm, camR.cameraMatrix, camR.distCorffs);

    //    // マーカの検出
    //    mrkr.calcPos(camL, camR);

    //    cv::imshow("capL", camL.dstIm);
    //    cv::imshow("capR", camR.dstIm);

    //    char c = cv::waitKey(1);
    //    if (c == 'q')
    //    {
    //        break;
    //    }
    //}

    //return 0;
}
