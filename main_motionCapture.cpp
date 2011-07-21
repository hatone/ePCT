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
	"MED_CON",	// 上の真ん中の凸
	"LAT_CON",	// 小転子
	"LAT_MALL", // 
	"MED_MALL", // 
	"fifTH_MTAR", // 
	"IL_CREST",   // 
	"HEEL"	// かかと
};

void cvmouse(int event, int x, int y, int flags, void *param)
{
    cv::Mat *im = static_cast<cv::Mat *>(param);

    switch (event)
    {
    case CV_EVENT_LBUTTONDOWN:
        clickPos.x = x; clickPos.y = y;
        cv::circle(*im, cv::Point(x, y), 5, cv::Scalar(0, 255, 0), -1);
        std::cout << "    " << x << ", " << y << std::endl;
        break;
    }
}

void initLabel(std::vector<cv::Point2f> &crrnt, std::vector<cv::Point2f> &prv)
{
    for (int i = MARKER_IDX_NUM-1; i >= 0; i--)
    {
        switch (i)
        {
		case FP1: // 大腿骨クラスタ
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FP2:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FP3:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FL1:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FL2:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FL3:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FA1:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FA2:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case FA3:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TL1: // 脛骨クラスタ
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TL2:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TL3:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TA1:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TA2:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case TA3:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;
		case GRT_TROC:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;   // 大転子
		case MED_CON:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;    // 上の真ん中の凸
		case LAT_CON:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;    // 小転子
		case LAT_MALL:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;   // 
		case MED_MALL:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;   // 
		case fifTH_MTAR:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;   // 
		case IL_CREST:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;   // 
		case HEEL:
			std::cout << markerName[i] << std::endl;
			cv::waitKey();
			mrkr.setOneMarkerLabel(i, clickPos, crrnt, prv);
			break;       // かかと
        }
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
    //capL.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    //capL.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    //capR.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    //capR.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    capL.set(CV_CAP_PROP_FRAME_WIDTH, 600);
    capL.set(CV_CAP_PROP_FRAME_HEIGHT, 400);
    capR.set(CV_CAP_PROP_FRAME_WIDTH, 600);
    capR.set(CV_CAP_PROP_FRAME_HEIGHT, 400);

    Camera camL, camR; // Webカメラ

    // キャリブレーションの準備
    camL.setUndistortParam();
    camR.setUndistortParam();

    cv::namedWindow("capL");
    cv::namedWindow("capR");

    cv::Mat frameLIm, frameRIm;

    // マーカのラベルの初期化
    // キャプチャ
    for (int i = 0; i < 5; i++)
    {
        capL >> frameLIm;
        capR >> frameRIm;
        cv::waitKey(10);
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

        //for (size_t i = 0; i < mrkr.crrntPosL.size(); i++)
        std::cout << "--" << std::endl;
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << mrkr.crrntPosL[mrkr.crrntPosL.size()-1-i].x << ", " << mrkr.crrntPosL[mrkr.crrntPosL.size()-1-i].y << std::endl;
        }
        std::cout << std::endl;
        cv::circle(camL.dstIm, mrkr.crrntPosL[mrkr.crrntPosL.size()-1], 5, cv::Scalar(255, 255, 0), -1);
        cv::circle(camL.dstIm, mrkr.crrntPosL[mrkr.crrntPosL.size()-2], 5, cv::Scalar(0, 255, 0), -1);
        cv::circle(camL.dstIm, mrkr.crrntPosL[mrkr.crrntPosL.size()-3], 5, cv::Scalar(0, 0, 255), -1);
        cv::circle(camR.dstIm, mrkr.crrntPosR[mrkr.crrntPosR.size()-1], 5, cv::Scalar(255, 255, 0), -1);
        cv::circle(camR.dstIm, mrkr.crrntPosR[mrkr.crrntPosR.size()-2], 5, cv::Scalar(0, 255, 0), -1);
        cv::circle(camR.dstIm, mrkr.crrntPosR[mrkr.crrntPosR.size()-3], 5, cv::Scalar(0, 0, 255), -1);

        cv::imshow("capL", camL.dstIm);
        cv::imshow("capR", camR.dstIm);

        char c = cv::waitKey();
        if (c == 'q')
        {
            break;
        }
    }

    return 0;
}
