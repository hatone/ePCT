/*! \file  mrStd.hpp
 *  \brief 自分で作った関数
 *
 *  gccで動作確認
 */

#ifndef _PCT_HPP_
#define _PCT_HPP_

class Vec4d
{
public:
    double x; //!< Vector of x
    double y; //!< Vector of y
    double z; //!< Vector of z
    double m; //!< Vector of m
    
    inline Vec4d(): x(0.0), y(0.0), z(0.0), m(0.0) {}
    inline Vec4d(double _x, double _y, double _z, double _m)
    {
        x = _x;
        y = _y;
        z = _z;
        m = _m;
    }
    
    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec4d prod(double n)
    {
        return Vec4d(x*n, y*n, z*n, m);
    }
    

    
};

/*!
 *  \class LoCoord
 *  \brief nya-
 *
 *
 */
class LoCoord{
public:
    std::vector<Vec3d> m_coordinates;
};

/*!
 *  \class GrCoord
 *  \brief bow
 *
 *
 */
class GrCoord{
public:
    std::vector<Vec4d> m_coordinates;
    
    
    inline void setCoord(std::vector<Vec4d> &coordinates)
    {
        m_coordinate = coordinate;
    }
    
};

/*!
 *  \class Cluster
 *  \brief local coordinate system
 *  
 *  It likes structure.
 */
class Cluster
{
    Vec3d x;
    Vec3d y;
    Vec3d z;
public:
    LoCoord L; //!< ローカル座標群
    GrCoord G; //!< グローバル座標群
    
    Vec3d cm; //!< 質量重心
};


#endif //  _PCT_HPP_
