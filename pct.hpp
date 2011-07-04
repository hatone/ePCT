/*!
 *  \file  pct.hpp
 *  \brief 
 */

#ifndef _PCT_HPP_
#define _PCT_HPP_

#include <cpplapack/cpplapack.h>

/*!
 *  \class LoCoord
 *  \brief ローカル座標
 *
 *
 */
class LoCoord{
public:
    std::vector<CPPL::dcovector> m_coordinates; // 座標
    
    /*!
     *  \brief m_coordinatesに座標を代入する
     *  
     *  \param  coordinates 代入する座標
     *  \return なし
     */
    inline void setCoord(std::vector<CPPL::dcovector> &coordinates)
    {
        m_coordinates = coordinates;
    }
};

/*!
 *  \class GrCoord
 *  \brief グローバル座標
 *
 *
 */
class GrCoord{
public:
    
    std::vector<CPPL::dcovector> m_coordinates;
    std::vector<CPPL::dcovector> l_coordinates; //どうしよう
    std::vector<double> m_mass;
    
    
    /*!
     *  \brief 任意の値をセットする？
     *  \param coordinate 代入したいグローバル座標群
     */
    inline void setCoord(std::vector<CPPL::dcovector> &coordinates)
    {
        m_coordinates = coordinates;
    }
    
    void weightFactor(CPPL::dcovector &C); /// 質量重心を求める
    
    /*!
     *  \brief L = R^t (G-C)
     *  \param 
     */
    inline void createLocal(std::vector<CPPL::dcovector> &L, CPPL::dcovector &wFact, std::vector<CPPL::dcovector> &vr)
    {
        std::vector<CPPL::dcovector> temp; //G-C
        CPPL::dgematrix R(3,3);
        
        //転置R作り
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                R(j,i)=vr[i](j);
            }
        }
        
        
        for(size_t i = 0; i < m_coordinates.size(); i++)
        {
            temp[i](0) = m_coordinates[i](0) - wFact(0);      
            temp[i](1) = m_coordinates[i](1) - wFact(1);   
            temp[i](2) = m_coordinates[i](2) - wFact(2);   
        }
        
        for(size_t i = 0; i < m_coordinates.size(); i++)
        {
            L[i]=R*temp[i];
        }
    }
    
};

/*!
 *  \class Cluster
 *  \brief ローカル座標系
 *  
 *  
 */
class Cluster
{
    //private:
public: // デバッグ用，本当はprivate
    CPPL::dcovector wFact; //!< 質量重心
    std::vector<CPPL::dcovector> P; //!< 慣性テンソル行列を生成するためのP(t)
    CPPL::dgematrix I; //!<慣性テンソル行列I(t)
    
    CPPL::dcovector pos;
    
    void weightFactor(); /// 質量重心を求める
    void createP(); /// 慣性テンソル行列を生成するためのP(t)iを求める
    void createTensor(); /// 慣性テンソル行列を生成するためのP(t)iを求める
public:
    LoCoord L; //!< ローカル座標群
    GrCoord G; //!< グローバル座標群
    
    CPPL::dcovector cm; //!< 質量重心
    
    Cluster();  /// Clusterのコンストラクタ
    ~Cluster(); /// Clusterのデストラクタ
    
    void pct(); /// PCTの計算
    
    void createLocalCoordinates(std::vector<CPPL::dcovector> &vr);
    
    void displayP();
};


#endif //  _PCT_HPP_
