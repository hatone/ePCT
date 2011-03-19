/*! \file  mrStd.hpp
 *  \brief 自分で作った関数
 *
 *  Visual Studio 2010 で動くはず
 */
#ifndef _MRSTD_HPP_
#define _MRSTD_HPP_

#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <map>

//#include <bzlib.h>
#include <boost/math/quaternion.hpp> 
//#include <boost\math\quaternion.hpp>

/*!
    *  \class Vec2i
    *  \brief Vector of Integer
    *  
    *  It likes structure.
    */
class Vec2i
{
public:
    int x; //!< Vector of x
    int y; //!< Vector of y

    inline Vec2i(): x(0), y(0) {}
    inline Vec2i(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2i operator+(const Vec2i &arg)
    {
        Vec2i v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2i operator+=(const Vec2i &arg)
    {
        x += arg.x;
        y += arg.y;

        return *this;
    }

    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec2i operator-(const Vec2i &arg)
    {
        Vec2i v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2i operator-=(const Vec2i &arg)
    {
        x -= arg.x;
        y -= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2i operator*(const Vec2i &arg)
    {
        Vec2i v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2i operator*=(const Vec2i &arg)
    {
        x *= arg.x;
        y *= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator * Overload
     *  \param arg parameter
     */
    inline Vec2i operator*(const int &arg)
    {
        Vec2i v;
        
        v.x = x * arg;
        v.y = y * arg;

        return v;
    }

    /*!
     *  \brief Operator *= Overload
     *  \param arg parameter
     */
    inline Vec2i operator*=(const int &arg)
    {
        x *= arg;
        y *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2i operator/(const Vec2i &arg)
    {
        Vec2i v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2i operator/=(const Vec2i &arg)
    {
        x /= arg.x;
        y /= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec2i operator/(const int &arg)
    {
        Vec2i v;
        
        v.x = x / arg;
        v.y = y / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec2i operator/=(const int &arg)
    {
        x /= arg;
        y /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec2i sum(Vec2i v)
    {
        return Vec2i(x+v.x, y+v.y);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec2i prod(int n)
    {
        return Vec2i(x*n, y*n);
    }
};

/*!
    *  \class Vec3i
    *  \brief Vector of Integer
    *  
    *  It likes structure.
    */
class Vec3i
{
public:
    int x; //!< Vector of x
    int y; //!< Vector of y
    int z; //!< Vector of z

    inline Vec3i(): x(0), y(0), z(0) {}
    inline Vec3i(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3i operator+(const Vec3i &arg)
    {
        Vec3i v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;
        v.z = z + arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3i operator+=(const Vec3i &arg)
    {
        x += arg.x;
        y += arg.y;
        z += arg.z;

        return *this;
    }

    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec3i operator-(const Vec3i &arg)
    {
        Vec3i v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;
        v.z = z - arg.z;

        return v;
    }

    /*!
     *  \brief Operator -= Overload
     *  \param arg parameter
     */
    inline Vec3i operator-=(const Vec3i &arg)
    {
        x -= arg.x;
        y -= arg.y;
        z -= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3i operator*(const Vec3i &arg)
    {
        Vec3i v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;
        v.z = z * arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3i operator*=(const Vec3i &arg)
    {
        x *= arg.x;
        y *= arg.y;
        z *= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3i operator*(const int &arg)
    {
        Vec3i v;
        
        v.x = x * arg;
        v.y = y * arg;
        v.z = z * arg;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3i operator*=(const int &arg)
    {
        x *= arg;
        y *= arg;
        z *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3i operator/(const Vec3i &arg)
    {
        Vec3i v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;
        v.z = z / arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3i operator/=(const Vec3i &arg)
    {
        x /= arg.x;
        y /= arg.y;
        z /= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec3i operator/(const double &arg)
    {
        Vec3i v;
        
        v.x = x / arg;
        v.y = y / arg;
        v.z = z / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec3i operator/=(const double &arg)
    {
        x /= arg;
        y /= arg;
        z /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec3i sum(Vec3i v)
    {
        return Vec3i(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec3i prod(int n)
    {
        return Vec3i(x*n, y*n, z*n);
    }
};

/*!
    *  \class Vec2f
    *  \brief Vector of float
    *  
    *  It likes structure.
    */
class Vec2f
{
public:
    float x; //!< Vector of x
    float y; //!< Vector of y

    inline Vec2f(): x(0.0f), y(0.0) {}
    inline Vec2f(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2f operator+(const Vec2f &arg)
    {
        Vec2f v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2f operator+=(const Vec2f &arg)
    {
        x += arg.x;
        y += arg.y;

        return *this;
    }

    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec2f operator-(const Vec2f &arg)
    {
        Vec2f v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;

        return v;
    }

    /*!
     *  \brief Operator -= Overload
     *  \param arg parameter
     */
    inline Vec2f operator-=(const Vec2f &arg)
    {
        x -= arg.x;
        y -= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2f operator*(const Vec2f &arg)
    {
        Vec2f v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2f operator*=(const Vec2f &arg)
    {
        x *= arg.x;
        y *= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator * Overload
     *  \param arg parameter
     */
    inline Vec2f operator*(const float &arg)
    {
        Vec2f v;
        
        v.x = x * arg;
        v.y = y * arg;

        return v;
    }

    /*!
     *  \brief Operator *= Overload
     *  \param arg parameter
     */
    inline Vec2f operator*=(const float &arg)
    {
        x *= arg;
        y *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2f operator/(const Vec2f &arg)
    {
        Vec2f v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2f operator/=(const Vec2f &arg)
    {
        x /= arg.x;
        y /= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec2f operator/(const float &arg)
    {
        Vec2f v;
        
        v.x = x / arg;
        v.y = y / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec2f operator/=(const float &arg)
    {
        x /= arg;
        y /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec2f sum(Vec2f v)
    {
        return Vec2f(x+v.x, y+v.y);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec2f prod(float n)
    {
        return Vec2f(x*n, y*n);
    }

    /*!
     *  \brief 正規化
     */
    inline void normalize()
    {
        float l = sqrt(x*x + y*y);

        if (l == 0.0f)
        {
            return;
        }

        l = 1 / l;

        x *= l;
        y *= l;
    }
};

/*!
    *  \class Vec3f
    *  \brief Vector of float
    *  
    *  It likes structure.
    */
class Vec3f
{
public:
    float x; //!< Vector of x
    float y; //!< Vector of y
    float z; //!< Vector of z

    inline Vec3f(): x(0.0f), y(0.0f), z(0.0f) {}
    inline Vec3f(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3f operator+(const Vec3f &arg)
    {
        Vec3f v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;
        v.z = z + arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3f operator+=(const Vec3f &arg)
    {
        x += arg.x;
        y += arg.y;
        z += arg.z;

        return *this;
    }
    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec3f operator-(const Vec3f &arg)
    {
        Vec3f v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;
        v.z = z - arg.z;

        return v;
    }

    /*!
     *  \brief Operator -= Overload
     *  \param arg parameter
     */
    inline Vec3f operator-=(const Vec3f &arg)
    {
        x -= arg.x;
        y -= arg.y;
        z -= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3f operator*(const Vec3f &arg)
    {
        Vec3f v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;
        v.z = z * arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3f operator*=(const Vec3f &arg)
    {
        x *= arg.x;
        y *= arg.y;
        z *= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator * Overload
     *  \param arg parameter
     */
    inline Vec3f operator*(const float &arg)
    {
        Vec3f v;
        
        v.x = x * arg;
        v.y = y * arg;
        v.z = z * arg;

        return v;
    }

    /*!
     *  \brief Operator *= Overload
     *  \param arg parameter
     */
    inline Vec3f operator*=(const float &arg)
    {
        x *= arg;
        y *= arg;
        z *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3f operator/(const Vec3f &arg)
    {
        Vec3f v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;
        v.z = z / arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3f operator/=(const Vec3f &arg)
    {
        x /= arg.x;
        y /= arg.y;
        z /= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec3f operator/(const float &arg)
    {
        Vec3f v;
        
        v.x = x / arg;
        v.y = y / arg;
        v.z = z / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec3f operator/=(const float &arg)
    {
        x /= arg;
        y /= arg;
        z /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec3f sum(Vec3f v)
    {
        return Vec3f(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec3f prod(float n)
    {
        return Vec3f(x*n, y*n, z*n);
    }

    /*!
     *  \brief 正規化
     */
    inline void normalize()
    {
        float l = sqrt(x*x + y*y + z*z);

        if (l == 0.0f)
        {
            return;
        }

        l = 1 / l;

        x *= l;
        y *= l;
        z *= l;
    }
};

/*!
    *  \class Vec2d
    *  \brief Vector of Double
    *  
    *  It likes structure.
    */
class Vec2d
{
public:
    double x; //!< Vector of x
    double y; //!< Vector of y

    inline Vec2d(): x(0), y(0) {}
    inline Vec2d(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2d operator+(const Vec2d &arg)
    {
        Vec2d v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2d operator+=(const Vec2d &arg)
    {
        x += arg.x;
        y += arg.y;

        return *this;
    }

    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec2d operator-(const Vec2d &arg)
    {
        Vec2d v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;

        return v;
    }

    /*!
     *  \brief Operator -= Overload
     *  \param arg parameter
     */
    inline Vec2d operator-=(const Vec2d &arg)
    {
        x -= arg.x;
        y -= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2d operator*(const Vec2d &arg)
    {
        Vec2d v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2d operator*=(const Vec2d &arg)
    {
        x *= arg.x;
        y *= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator * Overload
     *  \param arg parameter
     */
    inline Vec2d operator*(const double &arg)
    {
        Vec2d v;
        
        v.x = x * arg;
        v.y = y * arg;

        return v;
    }

    /*!
     *  \brief Operator *= Overload
     *  \param arg parameter
     */
    inline Vec2d operator*=(const double &arg)
    {
        x *= arg;
        y *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec2d operator/(const Vec2d &arg)
    {
        Vec2d v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec2d operator/=(const Vec2d &arg)
    {
        x /= arg.x;
        y /= arg.y;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec2d operator/(const double &arg)
    {
        Vec2d v;
        
        v.x = x / arg;
        v.y = y / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec2d operator/=(const double &arg)
    {
        x /= arg;
        y /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec2d sum(Vec2d v)
    {
        return Vec2d(x+v.x, y+v.y);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec2d prod(double n)
    {
        return Vec2d(x*n, y*n);
    }

    /*!
     *  \brief 正規化
     */
    inline void normalize()
    {
        double l = sqrt(x*x + y*y);

        if (l == 0.0f)
        {
            return;
        }

        l = 1 / l;

        x *= l;
        y *= l;
    }
};

/*!
    *  \class Vec3d
    *  \brief Vector of Integer
    *  
    *  It likes structure.
    */
class Vec3d
{
public:
    double x; //!< Vector of x
    double y; //!< Vector of y
    double z; //!< Vector of z

    inline Vec3d(): x(0), y(0), z(0) {}
    inline Vec3d(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3d operator+(const Vec3d &arg)
    {
        Vec3d v;
        
        v.x = x + arg.x;
        v.y = y + arg.y;
        v.z = z + arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3d operator+=(const Vec3d &arg)
    {
        x += arg.x;
        y += arg.y;
        z += arg.z;

        return *this;
    }
    /*!
     *  \brief Operator - Overload
     *  \param arg parameter
     */
    inline Vec3d operator-(const Vec3d &arg)
    {
        Vec3d v;
        
        v.x = x - arg.x;
        v.y = y - arg.y;
        v.z = z - arg.z;

        return v;
    }

    /*!
     *  \brief Operator -= Overload
     *  \param arg parameter
     */
    inline Vec3d operator-=(const Vec3d &arg)
    {
        x -= arg.x;
        y -= arg.y;
        z -= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator * Overload
     *  \param arg parameter
     */
    inline Vec3d operator*(const Vec3d &arg)
    {
        Vec3d v;
        
        v.x = x * arg.x;
        v.y = y * arg.y;
        v.z = z * arg.z;

        return v;
    }

    /*!
     *  \brief Operator *= Overload
     *  \param arg parameter
     */
    inline Vec3d operator*=(const Vec3d &arg)
    {
        x *= arg.x;
        y *= arg.y;
        z *= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3d operator*(const double &arg)
    {
        Vec3d v;
        
        v.x = x * arg;
        v.y = y * arg;
        v.z = z * arg;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3d operator*=(const double &arg)
    {
        x *= arg;
        y *= arg;
        z *= arg;

        return *this;
    }

    /*!
     *  \brief Operator + Overload
     *  \param arg parameter
     */
    inline Vec3d operator/(const Vec3d &arg)
    {
        Vec3d v;
        
        v.x = x / arg.x;
        v.y = y / arg.y;
        v.z = z / arg.z;

        return v;
    }

    /*!
     *  \brief Operator += Overload
     *  \param arg parameter
     */
    inline Vec3d operator/=(const Vec3d &arg)
    {
        x /= arg.x;
        y /= arg.y;
        z /= arg.z;

        return *this;
    }

    /*!
     *  \brief Operator / Overload
     *  \param arg parameter
     */
    inline Vec3d operator/(const double &arg)
    {
        Vec3d v;
        
        v.x = x / arg;
        v.y = y / arg;
        v.z = z / arg;

        return v;
    }

    /*!
     *  \brief Operator /= Overload
     *  \param arg parameter
     */
    inline Vec3d operator/=(const double &arg)
    {
        x /= arg;
        y /= arg;
        z /= arg;

        return *this;
    }

    /*!
     *  \brief 和
     *  \param n 足す数
     */
    inline Vec3d sum(Vec3d v)
    {
        return Vec3d(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief 積
     *  \param n 掛ける数
     */
    inline Vec3d prod(double n)
    {
        return Vec3d(x*n, y*n, z*n);
    }

    /*!
     *  \brief 正規化
     */
    inline void normalize()
    {
        double l = sqrt(x*x + y*y + z*z);

        if (l == 0.0f)
        {
            return;
        }

        l = 1 / l;

        x *= l;
        y *= l;
        z *= l;
    }
};


/*! \namespace mrMath
 *  \brief     数学に関する道具
 */
namespace mrMath
{
    // 定数
    const double M_PI_DBL      = 3.14159265358979323846; //!< 円周率
    const float  M_PI_FLT      = 3.141592654f;           //!< 円周率
    const float  M_PI_FLT_45   = 0.785398163f;           //!< 円周率の 1/4
    const float  M_PI_FLT_90   = 1.570796371f;           //!< 円周率の 1/2
    const float  M_PI_FLT_270  = 4.712388992f;           //!< 円周率の 3/2

    class omniNotation
    {
        std::vector<int> m_num; //!< 値

    public:
        /// コンストラクタ
        omniNotation();
        /// コンストラクタ
        omniNotation(std::string num);
        /// デストラクタ
        ~omniNotation();

        /// 値を出力する
        std::string show();
        
        /// 加算
        void add(std::string num);
        /// 乗算
        void multi(std::string num);
    };

    /*!
     *  \brief 0.5 は偶数側に丸める四捨五入
     *  \param n 丸める値
     *  \return  丸めた値
     */
    template <typename T> inline int round(T n)
    {
	    int in = static_cast<int>(floor(n));      // 整数部分
	    int dn = static_cast<int>(((n-in) * 10)); // 小数部分

	    if(dn > 5) // 小数点第一位が6以上
	    {
		    in += 1;
	    }
	    else if(dn == 5 && in%2 == 1)	//	小数点第一位が5で奇数
	    {
		    in += 1;
	    }

	    return in;
    }

    /*!
     *  \brief  合計を求める
     *  \param &v_data 入力
     *
     *  \return 合計
     */
    template <typename T> inline T summation(std::vector<T> &v_data)
    {
        T sum = 0;
        for (typename std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            sum += *it;
        }

        return sum;
    }

    /*!
     *  \brief  積を求める
     *  \param &v_data 入力
     *
     *  \return 合計
     */
    template <typename T> inline T multiplication(std::vector<T> &v_data)
    {
        T mul = 1;
        for (typename std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            mul *= *it;
        }

        return mul;
    }

    /*!
     *  \brief  平均を求める
     *  \param &v_data 入力データ
     *  
     *  \return 平均
     */
    template <typename T> inline double average(std::vector<T> &v_data)
    {
        return (summation(v_data) / v_data.size());
    }

    /*!
     *  \brief  分散を求める
     *  \param &v_data 入力データ
     *  
     *  \return 分散
     */
    template <typename T> inline double variance(std::vector<T> &v_data)
    {
        std::vector<T> v_pow; // 二乗の平均
        for (typename std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            v_pow.push_back(*it**it);
        }

	    return (average(v_pow) - pow(average(v_data), 2.0));
    }

    /*!
     *  \brief  シグモイド関数
     *
     *  f(x) = 1 / (1+\\exp(-x))
     *  \param  x           引数
     *  \param  temperature 影響の大きさ
     *  \return 計算結果
     */
    template <typename T> inline T sigmoid(T x, double temperature = 1.0)
    {
        return (1.0 / (1.0 + exp(-x / temperature)));
    }

    /*!
     * \brief  Degree を Radian に変換
     * \param  d Degree の値
     * \return Radian の値
     */
    template<typename T> T inline deg2rad(T d)
    {
        return d / 180.0 * M_PI_DBL;
    }

    /*!
     * \brief  Radian を Degree に変換
     * \param  r Radian の値
     * \return Degree の値
     */
    template<typename T> T inline rad2deg(T r) {
        return r / M_PI_DBL * 180.0;
    }

    /// 素因数分解
    void primeFactorization(unsigned int n, std::vector<int> &primeTable);

    /// 約数を求める
    void divisor(unsigned int n, std::vector<int> &divTable);

    /// 階乗を求める
    inline long long factorial(int n)
    {
        long long r = 1;
        for (int i = 2; i <= n; i++)
        {
            r *= i;
        }

        return r;
    }

    /// 組合せの数を求める
    long long combination(int n, int r);

    /*!
     *  \brief 内積を求める
     *  \param  l 左の項
     *  \param  r 右の項
     *  \return 内積
     */
    inline int innerProd(Vec3i &l, Vec3i &r)
    {
        return (l.x*r.x + l.y*r.y + l.z*r.z);
    }

    /*!
     *  \brief 外積を求める
     *  \param[in]  l 左の項
     *  \param[in]  r 右の項
     *  \param[out] a 外積
     */
    inline void outerProd(Vec3i &l, Vec3i &r, Vec3i &a)
    {
        a.x = l.y*r.z - l.z*r.y;
        a.y = l.z*r.x - l.x*r.z;
        a.z = l.x*r.y - l.y*r.x;
    }

    /// 任意軸回りの座標変換
    void quatRot(Vec3d src, Vec3d axis, double theta, Vec3d &dst);

}   // end of namespace mrMath

/*!
 *  \namespace mrString
 *  \brief     文字列に関する道具
 */
namespace mrString
{
    /// ランダム文字列を生成する
    void randamString(int length, std::string &rands);

    /// 文字列を分割して，string の std::vector に代入する
    void split(char *token, const char *delimit, std::vector <std::string> &v);

    /// 文字列を分割して，string の std::vector に代入する
    void split(std::string &token, const char *delimit, std::vector<std::string> &v);

}   // end of namespace mrString

/*!
 *  \namespace mrDebug
 *  \brief     デバッグに使う道具
 */
namespace mrDebug
{
    /*!
     *  \brief  std::vector の値を出力する．
     *
     *  std::vector の値を1行に1つずつ出力する．型は問わない．<br>
     *  区切り文字を導入しようd(･･
     *  \param  v 出力したい std::vector
     */
    template<typename T> void outputVector(std::vector<T> &v)
    {
        for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++){
			std::cout<<*it<<std::
			endl;
        }
    }
}	// end of namespace mrDebug

/*!
 *  \namespace mrUtil
 *  \brief     未分類の道具
 */
namespace mrUtil
{
    // マクロ
    #define	ArrLen(arr)  (sizeof(arr)/sizeof(arr[0])) //!< 配列の長さを返す

    /// std::vector を \a val で初期化する．
    template<typename T> void initVector(std::vector<T> &vctr, T val);

    /// スペース（' '）で区切られた csv ファイルを2次元 std::vector に読み込む．
    template<typename T> void csv2matrix(const char *fileName,std::vector<std::vector<T> > &matrix)
    {
		std::ifstream ifs(fileName);

        while (ifs && !ifs.eof())
        {
            std::string s;
            getline(ifs, s);
            std::istringstream is(s);

            T t;
            std::vector<T> v;
            while (is >> t)
            {
                v.push_back(t);
            }
            matrix.push_back(v);
        }

        ifs.close();
    }

    /*!
     *  \brief ベクトルの要素を入れ替える
     *  \param v ベクトル
     *  \param i 添字
     *  \param j 添字
     */
    template <typename T> inline void swapMember(std::vector<T> &v, int i, int j)
    {
        T tmp = v[i];
        v[i]  = v[j];
        v[j]  = tmp;
    }

    /// 素数テーブルを作成する
    //void makePrimeTable(std::vector<bool> &table);

    /// 回文かを判定する
    bool isPalindrome(std::string str);

    /*
     * \brief 2次元ベクトルを表示する
     * \param matrix 2次元ベクトル
     * \param format 表示フォーマット
     */
	template<typename T> void showVector(std::vector<std::vector<T> > &matrix, const std::string &format)
    {
        for (typename std::vector<std::vector<T> >::size_type y = 0; y < matrix.size(); y++)
        {
            for (typename std::vector<T>::size_type x = 0; x < matrix[y].size(); x++)
            {
                printf(format.c_str(), matrix[y][x]);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    /*
     * \brief 1次元ベクトルを表示する
     * \param matrix 1次元ベクトル
     * \param format 表示フォーマット
     */
    template<typename T> void showVector(std::vector<T> &vec, const std::string &format)
    {
        for (typename std::vector<T>::size_type x = 0; x < vec.size(); x++)
        {
            printf(format.c_str(), vec[x]);
        }
        std::cout << std::endl;
    }

    /*! \brief  配列の要素を入れ替える．
     *  \param  arr 入れ替えをされる配列
     *  \param  i 入れ替える要素の添え字
     *  \param  j 入れ替える要素の添え字
     */
    template<typename T> inline void swap(T arr[], T i, T j)
    {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}   // end of namespace mrUtil

#endif // _MRSTD_HPP_
