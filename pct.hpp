/*! \file  mrStd.hpp
 *  \brief 自分で作った関数
 *
 *  gccで動作確認
 */

#ifndef _PCT_HPP_
#define _PCT_HPP_

#include <cpplapack/cpplapack.h>

/*
// 本間用
#include <cpplapack.h>
*/


/*!
 *  \class LoCoord
 *  \brief This is Local coordinate class
 *
 *
 */
class LoCoord{
public:
    std::vector<Vec3d> m_coordinates;
};

/*!
 *  \class GrCoord
 *  \brief This is grobal coordinate class
 *
 *
 */
class GrCoord{
public:
    
    std::vector<Vec3d> m_coordinates;
    std::vector<double> m_mass;
    
    /*!
     *  \brief 任意の値をセットする？
     *  \param coordinate 代入したいグローバル座標群
     */
    inline void setCoord(std::vector<Vec3d> &coordinates)
    {
        m_coordinates = coordinates;
    }
    
    /*!
     *  \brief 質量重心
     *  \param coordinatesグローバル座標群, mass質量群
     */
    inline Vec3d weightFactor(std::vector<Vec3d> coordinates, std::vector<double> mass)
    {
        
        Vec3d c,gm;
        double m;
        
        for(int i=0; i< coordinates.size(); i++)
        {
            m = m + mass[i];
            gm=gm.sum( coordinates[i].prod(mass[i]) ); //gm+= g*m ;
            
        }
        c = gm.prod(1/m);
        return c;
    }
    
    /*!
     *  \brief 慣性テンソル行列を生成するためのP(t)iを求める
     *  \param coordinatesグローバル座標群, mass質量群
     */
    inline std::vector<Vec3d> createP(std::vector<Vec3d> coordinates, Vec3d wFact,std::vector<Vec3d> &p)
    {
        
        
        for(int i=0; i< coordinates.size(); i++)
        {
            p[i]=coordinates[i].sum(wFact.prod(-1));
            
        }
        
        return p;
    }
    
    
    /*!
     *  \brief 慣性テンソル行列を生成するためのP(t)iを求める
     *  \param coordinatesグローバル座標群, mass質量群
     */
    inline CPPL::dgematrix createTensor(std::vector<Vec3d> coordinates, std::vector<double> mass)
    {
        
        CPPL::dgematrix I(3,3);
        
        for(int i=0; i< coordinates.size(); i++)
        {
            I(0,0) += (coordinates[i].y * coordinates[i].y * mass[i]) + (coordinates[i].z * coordinates[i].z * mass[i]);
            I(0,1) += coordinates[i].x * coordinates[i].y * -1 * mass[i];
            I(0,2) += coordinates[i].x * coordinates[i].z * -1 * mass[i];
            
            I(1,0) += coordinates[i].x * coordinates[i].y * -1 * mass[i];
            I(1,1) += (coordinates[i].z * coordinates[i].z * mass[i])  + (coordinates[i].x * coordinates[i].x * mass[i]);   
            I(1,2) += coordinates[i].y * coordinates[i].z * -1 * mass[i];
            
            I(2,0) += coordinates[i].x * coordinates[i].z * -1 * mass[i];            
            I(2,1) += coordinates[i].y * coordinates[i].z * -1 * mass[i];
            I(2,2) += (coordinates[i].x * coordinates[i].x * mass[i])  + (coordinates[i].y * coordinates[i].y * mass[i]);  
            
        }
        
        return I;
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
