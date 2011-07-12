/*!
 *  \file capture.hpp
 *  \brief
 */

#ifndef _CAPTURE_HPP_
#define _CAPTURE_HPP_

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

// 奈良先端科学技術大学院大学 井村誠孝先生のラベリングクラス
// http://wikiwiki.jp/masayashi/?OpenCV%2F%A5%E9%A5%D9%A5%EA%A5%F3%A5%B0
#include "Labeling.h"

#include "mrCV.hpp"

/*!
 *  \namespace BUFFALO_BSW13K05H
 *  \brief BUFFALOのBSW13K05Hのレンズ歪み係数
 */
namespace BUFFALO_BSW13K05H
{
    const float  DISTANCE = 10.0f;
    const double HORIZONTAL_ANGLE_OF_VIEW = 80.0;
    const double VERTICAL_ANGLE_OF_VIEW = 60.0;

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
    float hViewAngle; //!< 水平画角
    float vViewAngle; //!< 鉛直画角

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
public: // デバッグ
    cv::Vec3f posA; //!< 底辺左端の座標
    cv::Vec3f posB; //!< 底辺右端の座標
    float baseLen;  //!< 底辺の長さ
    int imRows;     //!< 入力画像の幅
    int imColumns;  //!< 入力画像の高さ

    std::vector<cv::Point2f> crrntPosL; //!< 現在の座標
    std::vector<cv::Point2f> prvPosL;   //!< 1フレーム前の座標 
    std::vector<cv::Point2f> crrntPosR; //!< 現在の座標
    std::vector<cv::Point2f> prvPosR;   //!< 1フレーム前の座標 

    void getPos2D(cv::Mat &srcIm, cv::Mat &dstIm, std::vector<cv::Point2f> &pos); /// マーカの2次元座標を検出する
    void setMarkerLabel(); /// マーカにラベルを付ける
    cv::Vec3f triangulation(float angAh, float angAv, float angBh); /// 三角測量

    

    /*!
     *  \brief 画像の座標を角度に変換する
     *  \param pos 画像の座標
     *  \param max 画像の座標の最大値
     *  \return 角度（ラジアン）
     */
    inline float pos2rad(int pos, int width, int offset)
    {
        return ((static_cast<float>(pos)/static_cast<float>(width)) * 80.0f + offset);
    }

    /*!
     *  \brief ラジアンを度数に変換する
     *
     *  \param rad ラジアン
     */
    inline float rad2deg(float rad)
    {
        return (rad * 180.0/3.14159265358979323846);
    }

    /*!
     *  \brief 度数をラジアンに変換する
     *
     *  \param deg 度数
     */
    inline float deg2rad(float deg)
    {
        return (deg * 3.14159265358979323846/180.0);
    }

public:
    std::vector<cv::Point3f> crrntPos;  //!< 現在のグローバル座標
    std::vector<cv::Point3f> prvPos;    //!< 1フレーム前のグローバル座標

    Marker();  /// コンストラクタ
    ~Marker(); /// デストラクタ

    void calcPos(Camera &camL, Camera &camR); /// マーカの座標を検出する
};

#endif // _CAPTURE_HPP_