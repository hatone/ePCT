/*!
 *  \file capture.hpp
 *  \brief
 */

#ifndef _CAPTURE_HPP_
#define _CAPTURE_HPP_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include "mrCV.hpp"

/*!
 *  \namespace BUFFALO_BSW13K05H
 *  \brief BUFFALO��BSW13K05H�̃����Y�c�݌W��
 */
namespace BUFFALO_BSW13K05H
{
    const

    const double FOCUS_LEN_X = 610.67838569413459;
    const double FOCUS_LEN_Y = 612.43683758630948;
    const double PRINCIPAL_X = 329.5540547955984;
    const double PRINCIPAL_Y = 274.39840573846743;
    const double DIST1 = 0.19024649233571694;
    const double DIST2 = -0.86813017359471056;
    const double DIST3 = 0.00073867835617783884;
    const double DIST4 = 0.0033771420163482857;
}

/*!
 *  \class Camera
 *  \brief �J����
 */
class Camera
{
public:
    cv::Vec3f pos; //!< �J�����̍��W

    cv::Mat cameraMatrix; //!< �J�����s��
    cv::Mat distCorffs;   //!< �c�݌W��
    
    cv::Mat srcIm; //!< �I���W�i���̉摜
    cv::Mat dstIm; //!< �c�݂�␳�����摜

public:
    Camera();  /// �R���X�g���N�^
    ~Camera(); /// �f�X�g���N�^

    void setUndistortParam(); /// �L�����u���[�V�����̃p�����[�^�̐ݒ�
};

/*!
 *  \class Marker
 *  \brief �}�[�J�̍��W
 */
class Marker
{
    cv::Vec3f posA; //!< ��Ӎ��[�̍��W
    cv::Vec3f posB; //!< ��ӉE�[�̍��W
    float baseLen;  //!< ��ӂ̒���

    cv::Vec3f triangulation(float angAh, float angAv, float angBh); //!< �O�p����

    /*!
     *  \brief ���W�A����x���ɕϊ�����
     *
     *  \param rad ���W�A��
     */
    inline float rad2deg(float rad)
    {
        return (rad * 180.0f/3.14159265358979323846);
    }

    /*!
     *  \brief �x�������W�A���ɕϊ�����
     *
     *  \param deg �x��
     */
    inline float deg2rad(float deg)
    {
        return (deg * 3.14159265358979323846/180.0f);
    }

public:
    std::vector<cv::Vec3f> crrntPos; //!< ���݂̍��W
    std::vector<cv::Vec3f> prvPos;   //!< 1�t���[���O�̍��W 

    Marker();  /// �R���X�g���N�^
    ~Marker(); /// �f�X�g���N�^

    void calcPos(Camera camL, Camera camR); //!< �O�p����
};

#endif // _CAPTURE_HPP_