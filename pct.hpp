/*! \file  mrStd.hpp
 *  \brief 自分で作った関数
 *
 *  gccで動作確認
 */

#ifndef _PCT_HPP_
#define _PCT_HPP_

#include <cpplapack/cpplapack.h>

//#include <cpplapack.h>

/*!
 *  \class LoCoord
 *  \brief This is Local coordinate class
 *
 *
 */
class LoCoord{
public:
    std::vector<Vec3d> m_coordinates;
    
    
    inline void setCoord(std::vector<Vec3d> &coordinates)
    {
        m_coordinates = coordinates;
    }
    
    
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
    std::vector<Vec3d> l_coordinates; //どうしよう
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
    inline void weightFactor(Vec3d &C)
    {
        Vec3d gm;
        double m = 0.0;
        
        for(int i = 0; i < m_coordinates.size(); i++)
        {
            m += m_mass[i];
            gm += m_coordinates[i]*m_mass[i];
        }
        C = gm * (1.0/m);
    }
    
    /*!
     *  \brief 慣性テンソル行列を生成するためのP(t)iを求める
     *  \param coordinatesグローバル座標群, mass質量群
     */
    inline void createP(Vec3d &wFact,std::vector<Vec3d> &p)
    {
        p.reserve(m_coordinates.size());
        for (int i = 0; i< m_coordinates.size(); i++)
        {
            //p[i] = m_coordinates[i].sum(wFact.prod(-1));
            p.push_back(m_coordinates[i] + (wFact*(-1)));
        }
    }
    
    
    /*!
     *  \brief 慣性テンソル行列を生成するためのP(t)iを求める
     *  \param coordinatesグローバル座標群, mass質量群
     */
    inline void createTensor(CPPL::dgematrix I)
    {
        for(int i=0; i< m_coordinates.size(); i++)
        {
            I(0,0) += (m_coordinates[i].y * m_coordinates[i].y * m_mass[i]) + (m_coordinates[i].z * m_coordinates[i].z * m_mass[i]);
            I(0,1) += m_coordinates[i].x * m_coordinates[i].y * -1 * m_mass[i];
            I(0,2) += m_coordinates[i].x * m_coordinates[i].z * -1 * m_mass[i];
            
            I(1,0) += m_coordinates[i].x * m_coordinates[i].y * -1 * m_mass[i];
            I(1,1) += (m_coordinates[i].z * m_coordinates[i].z * m_mass[i])  + (m_coordinates[i].x * m_coordinates[i].x * m_mass[i]);   
            I(1,2) += m_coordinates[i].y * m_coordinates[i].z * -1 * m_mass[i];
            
            I(2,0) += m_coordinates[i].x * m_coordinates[i].z * -1 * m_mass[i];            
            I(2,1) += m_coordinates[i].y * m_coordinates[i].z * -1 * m_mass[i];
            I(2,2) += (m_coordinates[i].x * m_coordinates[i].x * m_mass[i])  + (m_coordinates[i].y * m_coordinates[i].y * m_mass[i]);  
            
        }
    }
    
    /*!
     *  \brief L = R^t (G-C)
     *  \param 
     */
    inline void createLocal(std::vector<CPPL::dcovector> &L,Vec3d &wFact,std::vector<CPPL::dcovector> &vr)
    {
        std::vector<CPPL::dcovector> temp; //G-C
        CPPL::dgematrix R;
        
        //転置R作り
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                R(j,i)=vr[i](j);
            }
        }
        
        
        for(int i=0; i< m_coordinates.size(); i++)
        {
            temp[i](0)=m_coordinates[i].x - wFact.x;      
            temp[i](1)=m_coordinates[i].y - wFact.y;   
            temp[i](2)=m_coordinates[i].z - wFact.z;   
        }
        
        for(int i=0; i< m_coordinates.size(); i++)
        {
            L[i]=R*temp[i];
        }
        
    
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
