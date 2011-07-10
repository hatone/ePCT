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
 *  \brief BUFFALOのBSW13K05Hのレンズ歪み係数
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
 *  \brief カメラ
 */
class Camera
{
public:
    cv::Vec3f pos; //!< カメラの座標

    cv::Mat cameraMatrix; //!< カメラ行列
    cv::Mat distCorffs;   //!< 歪み係数
    
    cv::Mat srcIm; //!< オリジナルの画像
    cv::Mat dstIm; //!< 歪みを補正した画像

public:
    Camera();  /// コンストラクタ
    ~Camera(); /// デストラクタ

    void setUndistortParam(); /// キャリブレーションのパラメータの設定
};

/*!
 *  \class Marker
 *  \brief マーカの座標
 */
class Marker
{
    cv::Vec3f posA; //!< 底辺左端の座標
    cv::Vec3f posB; //!< 底辺右端の座標
    float baseLen;  //!< 底辺の長さ

    cv::Vec3f triangulation(float angAh, float angAv, float angBh); //!< 三角測量

    /*!
     *  \brief ラジアンを度数に変換する
     *
     *  \param rad ラジアン
     */
    inline float rad2deg(float rad)
    {
        return (rad * 180.0f/3.14159265358979323846);
    }

    /*!
     *  \brief 度数をラジアンに変換する
     *
     *  \param deg 度数
     */
    inline float deg2rad(float deg)
    {
        return (deg * 3.14159265358979323846/180.0f);
    }

public:
    std::vector<cv::Vec3f> crrntPos; //!< 現在の座標
    std::vector<cv::Vec3f> prvPos;   //!< 1フレーム前の座標 

    Marker();  /// コンストラクタ
    ~Marker(); /// デストラクタ

    void calcPos(Camera camL, Camera camR); //!< 三角測量
};

#endif // _CAPTURE_HPP_