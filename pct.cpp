/*!
 *  \file  pct.cpp
 *  \brief 
 */
#include "pct.hpp"

Cluster::Cluster()
{
    wFact.resize(3);
    wFact.zero();
    I.resize(3, 3);
    I.zero();

    pos.resize(3);
    pos.zero();
    cm.resize(3);
    cm.zero();
}

Cluster::~Cluster()
{
}

void Cluster::createLocalCoordinates(std::vector<CPPL::dcovector> &vr)
{
    CPPL::dgematrix R(3,3);
    CPPL::dgematrix tR;//転置行列
    
    for(size_t i = 0; i < 3; i++)
    {
        for(size_t j = 0; j < 3; j++)
        {
            R(j,i) = vr[i](j);
        }
    }
    
    tR = CPPL::t(R);
    
    L.m_coordinates.resize(G.m_coordinates.size());
    
    for(size_t i = 0; i < G.m_coordinates.size(); i++)
    {
        L.m_coordinates[i] = tR*(G.m_coordinates[i]-wFact);
    }
}

void Cluster::pct()
{
    //ここに処理書く
    std::cout<<"PCT"<<std::endl;
    
    //質量重心算出
    weightFactor();
    std::cout << "C(t): " << std::endl;
    std::cout << wFact << std::endl;
    
    //慣性テンソル行列生成
    createP();
    std::cout << "P = " << std::endl;
    displayP();
    
    createTensor();
    std::cout << "I:" << std::endl;
    std::cout << I << std::endl;
    
    //慣性テンソル行列の固有と算出
    std::vector<double> wr, wi; //固有値 実数wr 虚数wi
    std::vector<CPPL::dcovector> vr, vi;//固有ベクトル 実数vr 虚数vi
    I.dgeev(wr,wi,vr,vi);  //いでよ固有値！固有ベクトル！！
    
    //表示系
    for(int i=0; i<3; i++){
        std::cout << "#### " << i << "th eigen ####" << std::endl;
        std::cout << "wr=" << wr[i] << std::endl;
        std::cout << "vr=\n" << vr[i] << std::endl;
    }
    
    createLocalCoordinates(vr);
    
    std::cout << "Local Coordinate -- " << std::endl;
    for (size_t i = 0; i < L.m_coordinates.size(); i++)
    {
        std::cout << L.m_coordinates[i] << std::endl;
        std::cout << "--" << std::endl;
    }
}

/*!
 *  
 */
void Cluster::weightFactor()
{
    double m = 0.0;
    
    for(size_t i = 0; i < G.m_coordinates.size(); i++)
    {
        m += G.m_mass[i];
        wFact += G.m_coordinates[i] * G.m_mass[i];
    }
    
    wFact /= m;
}

/*!
 *  \param coordinatesグローバル座標群, mass質量群
 */
void Cluster::createP()
{
    P.reserve(G.m_coordinates.size());
    for (size_t i = 0; i< G.m_coordinates.size(); i++)
    {
        P.push_back(G.m_coordinates[i] + wFact*(-1));
    }
}

/*!
 *  
 */
void Cluster::createTensor()
{
    for(size_t i = 0; i < P.size(); i++)
    {
        I(0,0) += (P[i](1) * P[i](1) * G.m_mass[i]) + (P[i](2) * P[i](2) * G.m_mass[i]);
        I(0,1) += P[i](0) * P[i](1) * -1 * G.m_mass[i];
        I(0,2) += P[i](0) * P[i](2) * -1 * G.m_mass[i];
        
        I(1,1) += (P[i](2) * P[i](2) * G.m_mass[i])  + (P[i](0) * P[i](0) * G.m_mass[i]);   
        I(1,2) += P[i](1) * P[i](2) * -1 * G.m_mass[i];
        
        I(2,2) += (P[i](0) * P[i](0) * G.m_mass[i])  + (P[i](1) * P[i](1) * G.m_mass[i]);  
    }
    
    I(1,0) = I(0,1);
    I(2,0) = I(0,2);
    I(2,1) = I(1,2);
}

void Cluster::redistributionMass()
{
}

void Cluster::displayP()
{
    printf("(     x,     y,     z)\n");
    for (size_t i = 0; i < P.size(); i++)
    {
        printf("( %3.3lf, %3.3lf, %3.3lf)\n",
               P[i](0), P[i](1), P[i](2));
    }
}
