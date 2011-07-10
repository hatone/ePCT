#include <iostream>

#include "capture.hpp"

/*!
 *
 */
Camera::Camera():
pos(cv::Vec3f(0.0f, 0.0f, 0.0f)),
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
Marker::Marker()
{
}

/*!
 *
 */
Marker::~Marker()
{
}

/*!
 *  �O�p���ʂ�crrntPos�Ƀ}�[�J���W���v�Z����D
 *  \param camL ���̃J����
 *  \param camR �E�̃J����
 */
void Marker::calcPos(Camera camL, Camera camR)
{
    baseLen = 10;

    triangulation(M_PI/3.0f, M_PI/6.0f, M_PI/6.0f);
}

/*!
 *  \param A ��Ӎ��[�̍��W
 *  \param B ��ӉE�[�̍��W
 *  \param baseLen ��ӂ̒���
 */
cv::Vec3f Marker::triangulation(float angAh, float angAv, float angBh)
{
    cv::Vec3f C;

    float angCh = M_PI - (angAh+angBh);
    float angCv = M_PI_2 - angAv;
    float sdAC = (sin(angBh)/sin(angCh)) * baseLen;

    float Xc = sdAC * sin(angAh);
    float Zc = sdAC * cos(angAh);
    float Yc = (sin(angAv)/sin(angCv)) * Zc;

    return C;
}
