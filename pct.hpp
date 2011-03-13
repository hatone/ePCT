/*! \file  mrStd.hpp
 *  \brief 自分で作った関数
 *
 *  gccで動作確認
 */

//#ifndef _PCT_HPP_
//#define _PCT_HPP_

class Vec4d
{
public:
    double x; //!< Vector of x
    double y; //!< Vector of y
    double z; //!< Vector of z
	double m; //!< Vector of m
	
    inline Vec4d(): x(0), y(0), z(0), m(0) {}
    inline Vec4d(double _x, double _y, double _z, double _m)
    {
        x = _x;
        y = _y;
        z = _z;
		m = _m;
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
public:
	//ローカルの座標系
    Vec3d x;
	Vec3d y;
	Vec3d z;
	
	//ローカル座標群
	class LoCoord{
	public:
		std::vector<Vec3d> m_coordinates;
	};
	
	//グローバル座標群
	class GrCoord{
	public:
		std::vector<Vec4d> m_coordinates;
	};
	
	//質量重心
	Vec3d cm;
};
