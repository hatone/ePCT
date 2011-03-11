/*! \file  mrStd.hpp
 *  \brief �����ō�����֐�
 *
 *  Visual Studio 2010 �œ����͂�
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

#include <bzlib.h>
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
    inline Vec2i(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec2i sum(Vec2i v)
    {
        return Vec2i(x+v.x, y+v.y);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
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
    inline Vec3i(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec3i sum(Vec3i v)
    {
        return Vec3i(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
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
    inline Vec2f(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec2f sum(Vec2f v)
    {
        return Vec2f(x+v.x, y+v.y);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
     */
    inline Vec2f prod(float n)
    {
        return Vec2f(x*n, y*n);
    }

    /*!
     *  \brief ���K��
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
    inline Vec3f(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec3f sum(Vec3f v)
    {
        return Vec3f(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
     */
    inline Vec3f prod(float n)
    {
        return Vec3f(x*n, y*n, z*n);
    }

    /*!
     *  \brief ���K��
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
    inline Vec2d(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec2d sum(Vec2d v)
    {
        return Vec2d(x+v.x, y+v.y);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
     */
    inline Vec2d prod(double n)
    {
        return Vec2d(x*n, y*n);
    }

    /*!
     *  \brief ���K��
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
    inline Vec3d(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    /*!
     *  \brief �a
     *  \param n ������
     */
    inline Vec3d sum(Vec3d v)
    {
        return Vec3d(x+v.x, y+v.y, z+v.z);
    }

    /*!
     *  \brief ��
     *  \param n �|���鐔
     */
    inline Vec3d prod(double n)
    {
        return Vec3d(x*n, y*n, z*n);
    }

    /*!
     *  \brief ���K��
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
 *  \brief     ���w�Ɋւ��铹��
 */
namespace mrMath
{
    // �萔
    const double M_PI_DBL      = 3.14159265358979323846; //!< �~����
    const float  M_PI_FLT      = 3.141592654f;           //!< �~����
    const float  M_PI_FLT_45   = 0.785398163f;           //!< �~������ 1/4
    const float  M_PI_FLT_90   = 1.570796371f;           //!< �~������ 1/2
    const float  M_PI_FLT_270  = 4.712388992f;           //!< �~������ 3/2

    class omniNotation
    {
        std::vector<int> m_num; //!< �l

    public:
        /// �R���X�g���N�^
        omniNotation();
        /// �R���X�g���N�^
        omniNotation(std::string num);
        /// �f�X�g���N�^
        ~omniNotation();

        /// �l���o�͂���
        std::string show();
        
        /// ���Z
        void add(std::string num);
        /// ��Z
        void multi(std::string num);
    };

    /*!
     *  \brief 0.5 �͋������Ɋۂ߂�l�̌ܓ�
     *  \param n �ۂ߂�l
     *  \return  �ۂ߂��l
     */
    template <typename T> inline int round(T n)
    {
	    int in = static_cast<int>(floor(n));      // ��������
	    int dn = static_cast<int>(((n-in) * 10)); // ��������

	    if(dn > 5) // �����_���ʂ�6�ȏ�
	    {
		    in += 1;
	    }
	    else if(dn == 5 && in%2 == 1)	//	�����_���ʂ�5�Ŋ
	    {
		    in += 1;
	    }

	    return in;
    }

    /*!
     *  \brief  ���v�����߂�
     *  \param &v_data ����
     *
     *  \return ���v
     */
    template <typename T> inline T summation(std::vector<T> &v_data)
    {
        T sum = 0;
        for (std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            sum += *it;
        }

        return sum;
    }

    /*!
     *  \brief  �ς����߂�
     *  \param &v_data ����
     *
     *  \return ���v
     */
    template <typename T> inline T multiplication(std::vector<T> &v_data)
    {
        T mul = 1;
        for (std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            mul *= *it;
        }

        return mul;
    }

    /*!
     *  \brief  ���ς����߂�
     *  \param &v_data ���̓f�[�^
     *  
     *  \return ����
     */
    template <typename T> inline double average(std::vector<T> &v_data)
    {
        return (summation(v_data) / v_data.size());
    }

    /*!
     *  \brief  ���U�����߂�
     *  \param &v_data ���̓f�[�^
     *  
     *  \return ���U
     */
    template <typename T> inline double variance(std::vector<T> &v_data)
    {
        std::vector<T> v_pow; // ���̕���
        for (std::vector<T>::iterator it = v_data.begin(); it != v_data.end(); it++)
        {
            v_pow.push_back(*it**it);
        }

	    return (average(v_pow) - pow(average(v_data), 2.0));
    }

    /*!
     *  \brief  �V�O���C�h�֐�
     *
     *  f(x) = 1 / (1+\\exp(-x))
     *  \param  x           ����
     *  \param  temperature �e���̑傫��
     *  \return �v�Z����
     */
    template <typename T> inline T sigmoid(T x, double temperature = 1.0)
    {
        return (1.0 / (1.0 + exp(-x / temperature)));
    }

    /*!
     * \brief  Degree �� Radian �ɕϊ�
     * \param  d Degree �̒l
     * \return Radian �̒l
     */
    template<typename T> T inline deg2rad(T d)
    {
        return d / 180.0 * M_PI_DBL;
    }

    /*!
     * \brief  Radian �� Degree �ɕϊ�
     * \param  r Radian �̒l
     * \return Degree �̒l
     */
    template<typename T> T inline rad2deg(T r) {
        return r / M_PI_DBL * 180.0;
    }

    /// �f��������
    void primeFactorization(unsigned int n, std::vector<int> &primeTable);

    /// �񐔂����߂�
    void divisor(unsigned int n, std::vector<int> &divTable);

    /// �K������߂�
    inline long long factorial(int n)
    {
        long long r = 1;
        for (int i = 2; i <= n; i++)
        {
            r *= i;
        }

        return r;
    }

    /// �g�����̐������߂�
    long long combination(int n, int r);

    /*!
     *  \brief ���ς����߂�
     *  \param  l ���̍�
     *  \param  r �E�̍�
     *  \return ����
     */
    inline int innerProd(Vec3i &l, Vec3i &r)
    {
        return (l.x*r.x + l.y*r.y + l.z*r.z);
    }

    /*!
     *  \brief �O�ς����߂�
     *  \param[in]  l ���̍�
     *  \param[in]  r �E�̍�
     *  \param[out] a �O��
     */
    inline void outerProd(Vec3i &l, Vec3i &r, Vec3i &a)
    {
        a.x = l.y*r.z - l.z*r.y;
        a.y = l.z*r.x - l.x*r.z;
        a.z = l.x*r.y - l.y*r.x;
    }

    /// �C�ӎ����̍��W�ϊ�
    void quatRot(Vec3d src, Vec3d axis, double theta, Vec3d &dst);

}   // end of namespace mrMath

/*!
 *  \namespace mrString
 *  \brief     ������Ɋւ��铹��
 */
namespace mrString
{
    /// �����_��������𐶐�����
    void randamString(int length, std::string &rands);

    /// ������𕪊����āCstring �� std::vector �ɑ������
    void split(char *token, const char *delimit, std::vector <std::string> &v);

    /// ������𕪊����āCstring �� std::vector �ɑ������
    void split(std::string &token, const char *delimit, std::vector<std::string> &v);

}   // end of namespace mrString

/*!
 *  \namespace mrDebug
 *  \brief     �f�o�b�O�Ɏg������
 */
namespace mrDebug
{
    /*!
     *  \brief  std::vector �̒l���o�͂���D
     *
     *  std::vector �̒l��1�s��1���o�͂���D�^�͖��Ȃ��D<br>
     *  ��؂蕶���𓱓����悤d(��
     *  \param  v �o�͂����� std::vector
     */
    template<typename T> void outputVector(std::vector<T> &v)
    {
        for (std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *it << endl;
        }
    }
}	// end of namespace mrDebug

/*!
 *  \namespace mrUtil
 *  \brief     �����ނ̓���
 */
namespace mrUtil
{
    // �}�N��
    #define	ArrLen(arr)  (sizeof(arr)/sizeof(arr[0])) //!< �z��̒�����Ԃ�

    /// std::vector �� \a val �ŏ���������D
    template<typename T> void initVector(std::vector<T> &vctr, T val);

    /// �X�y�[�X�i' '�j�ŋ�؂�ꂽ csv �t�@�C����2���� std::vector �ɓǂݍ��ށD
    template<typename T> void csv2matrix(const char *fileName, std::vector<std::vector<T>> &matrix)
    {
        ifstream ifs(fileName);

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
     *  \brief �x�N�g���̗v�f�����ւ���
     *  \param v �x�N�g��
     *  \param i �Y��
     *  \param j �Y��
     */
    template <typename T> inline void swapMember(std::vector<T> &v, int i, int j)
    {
        T tmp = v[i];
        v[i]  = v[j];
        v[j]  = tmp;
    }

    /// �f���e�[�u�����쐬����
    //void makePrimeTable(std::vector<bool> &table);

    /// �񕶂��𔻒肷��
    bool isPalindrome(std::string str);

    /*
     * \brief 2�����x�N�g����\������
     * \param matrix 2�����x�N�g��
     * \param format �\���t�H�[�}�b�g
     */
    template<typename T> void showVector(std::vector<std::vector<T> > &matrix, const std::string &format)
    {
        for (std::vector<std::vector<T> >::size_type y = 0; y < matrix.size(); y++)
        {
            for (std::vector<T>::size_type x = 0; x < matrix[y].size(); x++)
            {
                printf(format.c_str(), matrix[y][x]);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    /*
     * \brief 1�����x�N�g����\������
     * \param matrix 1�����x�N�g��
     * \param format �\���t�H�[�}�b�g
     */
    template<typename T> void showVector(std::vector<T> &vec, const std::string &format)
    {
        for (std::vector<T>::size_type x = 0; x < vec.size(); x++)
        {
            printf(format.c_str(), vec[x]);
        }
        std::cout << std::endl;
    }

    /*! \brief  �z��̗v�f�����ւ���D
     *  \param  arr ����ւ��������z��
     *  \param  i ����ւ���v�f�̓Y����
     *  \param  j ����ւ���v�f�̓Y����
     */
    template<typename T> inline void swap(T arr[], T i, T j)
    {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}   // end of namespace mrUtil

#endif // _MRSTD_HPP_
