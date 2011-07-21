/*!
 *  \file capture.hpp
 *  \brief
 */

#ifndef _CAPTURE_HPP_
#define _CAPTURE_HPP_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

// �ޗǐ�[�Ȋw�Z�p��w�@��w �䑺���F�搶�̃��x�����O�N���X
// http://wikiwiki.jp/masayashi/?OpenCV%2F%A5%E9%A5%D9%A5%EA%A5%F3%A5%B0
#include "Labeling.h"

#include "mrCV.hpp"

/*!
 *  \namespace BUFFALO_BSW13K05H
 *  \brief BUFFALO��BSW13K05H�̃����Y�c�݌W��
 */
namespace BUFFALO_BSW13K05H
{
    const float  DISTANCE = 10.0f;
    const double ANGLE_OF_VIEW_H = 1.3962634015954636; // ���������̎���p�D80�x
    const double ANGLE_OFFSET_H = 0.87266462599716477; // ���������̎���O�̊p�x�D50�x
    const double ANGLE_OF_VIEW_V = 1.0471975511965976; // ���������̎���p�D60�x
    const double ANGLE_OFFSET_V = 1.0471975511965976; // ���������̎���O�̊p�x�D60�x

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
 *  \enum MARKER_IDX
 *  \brief ���t�@�����X�}�[�J
 */
enum MARKER_IDX
{
    FP1 = 0, // ��ڍ��N���X�^
    FP2,
    FP3,
    FL1,
    FL2,
    FL3,
    FA1,
    FA2,
    FA3,
    TL1,    // �����N���X�^
    TL2,
    TL3,
    TA1,
    TA2,
    TA3,
    GRT_TROC,   // ��]�q
    MED_CON,    // ��̐^�񒆂̓�
    LAT_CON,    // ���]�q
    LAT_MALL,   // 
    MED_MALL,   // 
    fifTH_MTAR,   // 
    IL_CREST,   // 
    HEEL,       // ������
    MARKER_IDX_NUM // �}�[�J�̐�
};

/*!
 *  \class Camera
 *  \brief �J����
 */
class Camera
{
public:
    cv::Vec3f pos; //!< �J�����̍��W
    float hViewAngle; //!< ������p
    float vViewAngle; //!< ������p

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
public: // �f�o�b�O
    cv::Vec3f posA; //!< ��Ӎ��[�̍��W
    cv::Vec3f posB; //!< ��ӉE�[�̍��W
    float baseLen;  //!< ��ӂ̒���
    int imRows;     //!< ���͉摜�̕�
    int imCols;  //!< ���͉摜�̍���

    std::vector<cv::Point2f> crrntPosL; //!< ���݂̍��W
    std::vector<cv::Point2f> prvPosL;   //!< 1�t���[���O�̍��W 
    std::vector<cv::Point2f> crrntPosR; //!< ���݂̍��W
    std::vector<cv::Point2f> prvPosR;   //!< 1�t���[���O�̍��W 

    void getPos2D(cv::Mat &srcIm, cv::Mat &dstIm, std::vector<cv::Point2f> &pos); /// �}�[�J��2�������W�����o����
    void getPos3D(); /// �}�[�J��3�������W�����߂�
    void setMarkerLabel(std::vector<cv::Point2f> &prv, std::vector<cv::Point2f> &crrnt); /// �}�[�J�Ƀ��x����t����
    cv::Vec3f triangulation(float angAh, float angAv, float angBh); /// �O�p����

    /*!
     *  \brief �_�Ɠ_�̋��������߂�
     *  \param �_
     *  \param �_
     */
    inline float distance(cv::Point2f pos1, cv::Point2f pos2)
    {
        return sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x) + (pos1.y-pos2.y)*(pos1.y-pos2.y));
    }

    /*!
     *  \brief �摜�̐��������̍��W���p�x�ɕϊ�����
     *  \param pos �摜�̍��W
     *  \param max �摜�̍��W�̍ő�l
     *  \return �p�x�i���W�A���j
     */
    inline float pos2radH(int pos)
    {
        return ((static_cast<float>(pos)/static_cast<float>(imRows)) * BUFFALO_BSW13K05H::ANGLE_OF_VIEW_H + BUFFALO_BSW13K05H::ANGLE_OFFSET_H);
    }

    /*!
     *  \brief �摜�̉��������̍��W���p�x�ɕϊ�����
     *  \param pos �摜�̍��W
     *  \param max �摜�̍��W�̍ő�l
     *  \return �p�x�i���W�A���j
     */
    inline float pos2radV(int pos)
    {
        return ((static_cast<float>(pos)/static_cast<float>(imCols)) * BUFFALO_BSW13K05H::ANGLE_OF_VIEW_V + BUFFALO_BSW13K05H::ANGLE_OFFSET_V);
    }

    /*!
     *  \brief ���W�A����x���ɕϊ�����
     *
     *  \param rad ���W�A��
     */
    inline float rad2deg(float rad)
    {
        return (rad * 180.0/3.14159265358979323846);
    }

    /*!
     *  \brief �x�������W�A���ɕϊ�����
     *
     *  \param deg �x��
     */
    inline float deg2rad(float deg)
    {
        return (deg * 3.14159265358979323846/180.0);
    }

public:
    std::vector<cv::Point3f> crrntPos;  //!< ���݂̃O���[�o�����W
    std::vector<cv::Point3f> prvPos;    //!< 1�t���[���O�̃O���[�o�����W

    Marker();  /// �R���X�g���N�^
    ~Marker(); /// �f�X�g���N�^

    void calcPos(Camera &camL, Camera &camR); /// �}�[�J�̍��W�����o����
    void setOneMarkerLabel(int idx, cv::Point2i pos, std::vector<cv::Point2f> &crrnt, std::vector<cv::Point2f> &prv); /// 1�̃}�[�J�Ƀ��x����t����
    MARKER_IDX getMarkerIdx(cv::Point2i pos); /// �߂��ɂ���}�[�J�̓Y�����擾����
};

#endif // _CAPTURE_HPP_