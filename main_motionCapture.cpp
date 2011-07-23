#include <iostream>
#include <cmath>

#include <mrCV.hpp>

#include "C:\\Users\\Takushi\\git\\ePCT\\capture.hpp"
//#include "capture.hpp"

Marker mrkr;       // マーカ
cv::Point2i clickPos; // マウスでクリックした座標

char *markerName[] = {
	"FP1", // 大腿骨クラスタ
	"FP2",
	"FP3",
	"FL1",
	"FL2",
	"FL3",
	"FA1",
	"FA2",
	"FA3",
	"TL1", // 脛骨クラスタ
	"TL2",
	"TL3",
	"TA1",
	"TA2",
	"TA3",
	"GRT_TROC", // 大転子
	"MED_CON",	// 大腿骨内側顆
	"LAT_CON",	// 大腿骨外側顆
	"LAT_PLA",	// 外側プラトー
	"MED_PLA",	// 内側プラトー
	"LAT_MALL", // 脛骨外側顆
	"MED_MALL", // 脛骨内側顆
	"fifTH_MTAR", // 第5中足骨
	"IL_CREST",   // 骨盤
	"HEEL"	// かかと
};

cv::Scalar COLOR[] = {
    cv::Scalar(0x71, 0xb3, 0x3c), // 大腿骨クラスタ
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x71, 0xb3, 0x3c),
    cv::Scalar(0x00, 0xa5, 0xff), // 脛骨クラスタ
    cv::Scalar(0x00, 0xa5, 0xff),
    cv::Scalar(0x00, 0xa5, 0xff),
    cv::Scalar(0x00, 0xa5, 0xff),
    cv::Scalar(0x00, 0xa5, 0xff),
    cv::Scalar(0x00, 0xa5, 0xff),
    cv::Scalar(0xff, 0x00, 0x00), // 大転子
    cv::Scalar(0xff, 0xbf, 0x00), // 大腿骨外側顆
    cv::Scalar(0xff, 0xff, 0x00), // 大腿骨内側顆
    cv::Scalar(0xe2, 0x2b, 0x8a), // 外側プラトー
    cv::Scalar(0xd6, 0x70, 0xda), // 内側プラトー
    cv::Scalar(0x00, 0x00, 0xff), // 脛骨外側顆
    cv::Scalar(0x5c, 0x5c, 0xcd), // 脛骨内側顆
    cv::Scalar(0xff, 0x00, 0xff), // 第5中足骨
    cv::Scalar(0x66, 0x66, 0x66), // 骨盤?
    cv::Scalar(0xb4, 0x69, 0xff), // かかと
};


void cvmouse(int event, int x, int y, int flags, void *param)
{
    cv::Mat *im = static_cast<cv::Mat *>(param);

    switch (event)
    {
    case CV_EVENT_LBUTTONDOWN:
        clickPos.x = x; clickPos.y = y;
        std::cout << "    " << x << ", " << y << std::endl;
        break;
    }
}

void initLabel(std::vector<cv::Point2f> &crrnt, std::vector<cv::Point2f> &prv)
{
    for (int i = MARKER_IDX_NUM-1; i >= 0; i--)
    {
        std::cout << markerName[i] << std::endl;
		cv::waitKey();
		mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
    }
}

int main(int argc, char *argv[])
{
    // カメラ画像
    //cv::VideoCapture capL(0), capR(0);
    //cv::VideoCapture capL(1), capR(1);
    cv::VideoCapture capL(1), capR(2);
    if (!capL.isOpened())
    {
        return -1;
    }
    capL.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capL.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    capR.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capR.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    //capL.set(CV_CAP_PROP_FRAME_WIDTH, 600);
    //capL.set(CV_CAP_PROP_FRAME_HEIGHT, 400);
    //capR.set(CV_CAP_PROP_FRAME_WIDTH, 600);
    //capR.set(CV_CAP_PROP_FRAME_HEIGHT, 400);

    Camera camL, camR; // Webカメラ

    // キャリブレーションの準備
    camL.setUndistortParam();
    camR.setUndistortParam();

    cv::namedWindow("capL");
    cv::namedWindow("capR");

    cv::Mat frameLIm, frameRIm;

    // マーカのラベルの初期化
    // キャプチャ
    for (int i = 0; i < 20; i++)
    {
        capL >> frameLIm;
        capR >> frameRIm;
        cv::imshow("capL", frameLIm);
        cv::imshow("capR", frameRIm);
        cv::waitKey(1);
    }

    // キャリブレーション
    cv::undistort(frameLIm, camL.srcIm, camL.cameraMatrix, camL.distCorffs);
    cv::undistort(frameRIm, camR.srcIm, camR.cameraMatrix, camR.distCorffs);

    // マーカの検出
    mrkr.getPos2D(camL.srcIm, camL.dstIm, mrkr.crrntPosL);
    mrkr.getPos2D(camR.srcIm, camR.dstIm, mrkr.crrntPosR);

    cv::imshow("capL", camL.dstIm);
    cv::imshow("capR", camR.dstIm);

    // マウス
    cvSetMouseCallback("capL", (CvMouseCallback)(&cvmouse), &camL.dstIm);
    initLabel(mrkr.crrntPosL, mrkr.prvPosL);
    cvSetMouseCallback("capR", (CvMouseCallback)(&cvmouse), &camR.dstIm);
    initLabel(mrkr.crrntPosR, mrkr.prvPosR);


    while (true)
    {
        // キャプチャ
        capL >> frameLIm;
        capR >> frameRIm;

        // キャリブレーション
        cv::undistort(frameLIm, camL.srcIm, camL.cameraMatrix, camL.distCorffs);
        cv::undistort(frameRIm, camR.srcIm, camR.cameraMatrix, camR.distCorffs);

        // マーカの検出
        mrkr.calcPos(camL, camR);

        for (int i = 0; i < 25; i++)
        {
            cv::circle(camL.dstIm, mrkr.crrntPosL[i], 5, COLOR[i], -1);
            cv::circle(camR.dstIm, mrkr.crrntPosR[i], 5, COLOR[i], -1);
        }

        std::cout << "pos" << std::endl;
        std::cout << mrkr.crrntPos[0].x << ", " << mrkr.crrntPos[0].y << ", " << mrkr.crrntPos[0].z << std::endl;

        cv::imshow("capL", camL.dstIm);
        cv::imshow("capR", camR.dstIm);

        char c = cv::waitKey(1);
        if (c == 'q')
        {
            break;
        }
    }

    return 0;
}
