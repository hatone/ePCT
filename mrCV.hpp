/* \file  moruCV.hpp
 * \brief OpenCVを利用する
 */
#ifndef _MORUCV_HPP_
#define _MORUCV_HPP_

#pragma warning(disable: 4996)
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#pragma warning(default: 4996)

#ifdef _DEBUG
    //Debugモードの場合
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Debug\\cv210d.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Debug\\cxcore210d.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Debug\\cvaux210d.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Debug\\highgui210d.lib")
#else
    //Releaseモードの場合
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Release\\cv210.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Release\\cxcore210.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Release\\cvaux210.lib")
    #pragma comment(lib,"C:\\Users\\Takushi\\library\\OpenCV2.1\\build\\lib\\Release\\highgui210.lib")
#endif

namespace mrCV
{
    namespace KEY
    {
        const int LEFT  = 0x250000;
        const int UP    = 0x260000;
        const int RIGHT = 0x270000;
        const int DOWN  = 0x280000;
    }
}

#endif // _MORUCV_HPP_