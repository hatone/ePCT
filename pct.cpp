/*!
 *  \file  pct.cpp
 *  \brief 
 */
#include "pct.hpp"
#include <cmath>
#define PI 3.141592653589793



enum MARKER_IDX_F {
FP1,
FP2,
FP3,
FL1,
FL2,
FL3,
FA1,
FA2,
FA3,
GRT_TROC,		
MED_CON,		
LAT_CON
};

enum MARKER_IDX_T {
TL1,
TL2,		
TL3,
TA1,
TA2,
TA3,
LAT_MALL,
MED_MALL,
FIFTH_MTAR,
IL_CREST,
HEEL
};

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

    axis.resize(2, CPPL::dcovector(3));
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

void Cluster::redistributionMass(Cluster &C)
{
    typedef std::pair<double*, double> pd; // m_massのアドレスと距離
    
    //慣性主軸間距離(固有ベクトルと各グローバル座標の距離)を求める
    std::vector <pd> pv;
    
    
    for(size_t i=0; i< G.m_coordinates.size(); i++)
    {
        
        double dst=0;//慣性主軸間距離
        
        
        for(size_t j=0; j<3; j++)
        {
            dst+=abs( vr[j](0)*G.m_coordinates[i](0) +vr[j](1)*G.m_coordinates[i](1)+vr[j](2)*G.m_coordinates[i](2) ) / 
            sqrt(G.m_coordinates[i](0)*G.m_coordinates[i](0)+G.m_coordinates[i](1)*G.m_coordinates[i](1)+G.m_coordinates[i](2)*G.m_coordinates[i](2));
        }
        
         std::cout<<"s dst"<<i<<" "<<dst<<std::endl;
        
        int idx= -1;
        for(size_t j=0; j<pv.size(); j++)
        {
        
            if(dst >= pv[j].second)
            {
                idx=j;
                break;
            }
        }
        
        if(idx==-1)
        {
            pv.push_back(pd(&G.m_mass[i], dst));
        }
        else 
        {
            std::vector<pd>::iterator it = pv.begin();	
            advance(it,idx);
            pv.insert(it,pd(&G.m_mass[i], dst));
        }
     }       
    
    for(size_t i=0; i< G.m_mass.size(); i++)
    {
        *pv[i].first = i/(G.m_mass.size()-1);
    }
            
    
    
}

void calcAxsis(Cluster &F,Cluster &T, CPPL::dcovector &angle,CPPL::dcovector &dist)
{   
    //初期化
    CPPL::dcovector Fdist(3);
    CPPL::dcovector Tdist(3);
    
    //軸を算出
    F.createFAxsis();
    T.createTAxsis();

    for(size_t i=0; i<3; i++)
    {
        dist(i)=sqrt( (F.axis[0](i)-T.axis[0](i)) * (F.axis[0](i)-T.axis[0](i)) );
    }
    
    
    //原点へ。軸の始点と終点をずらす
    F.axis[1] -= F.axis[0];
    T.axis[1] -= T.axis[0];
    
    //軸の距離を求める&&角度を求める
    for(size_t i=0; i<3; i++)
    {
        Fdist(i)= sqrt(F.axis[1](i)*F.axis[1](i));
        Tdist(i)= sqrt(T.axis[1](i)*T.axis[1](i));

        angle(i)=acos(Fdist(i)/Tdist(i))* 180.0 / PI;
    }
    
    
}


void Cluster::createFAxsis()
{
    std::cout << "createFAxis" << std::endl;
    
    CPPL::dcovector vMid(3);
    CPPL::dcovector vS(3);
    CPPL::dcovector vX(3);
    CPPL::dcovector vY(3);
    CPPL::dcovector vZ(3);

    vMid=(L.m_coordinates[MED_CON]+L.m_coordinates[LAT_CON])/2.0;
//    std::cout << "MED_COM = \n" << L.m_coordinates[MED_CON] << std::endl;
//    std::cout << "LAT_COM = \n" << L.m_coordinates[LAT_CON] << std::endl;
//    std::cout<<"vMid\n"<<vMid<<std::endl;
    vS=L.m_coordinates[LAT_CON];
    vX=L.m_coordinates[MED_CON];
    vY=L.m_coordinates[GRT_TROC];

    std::cout << "posS = " << std::endl;
    std::cout << vS << std::endl;
//    std::cout << "posX = " << std::endl;
//    std::cout << vX << std::endl;
//    std::cout << "posY = " << std::endl;
//    std::cout << vY << std::endl;

    vX -= vS;
    vY -= vS;
    vZ = cross(vX, vY);
    
//    std::cout << "vecX = " << std::endl;
//    std::cout << vX<< std::endl;
    std::cout << "vecY = " << std::endl;
    std::cout << vY<< std::endl;
    std::cout << "vecZ = " << std::endl;
    std::cout << vZ << std::endl;
    
    vX = cross(vZ,vY);

//中点へ移動
    vS -= vMid;
    vX -= vMid;
    vY -= vMid;
    vZ -= vMid;
    
    
    std::cout << "vecX = " << std::endl;
    std::cout << vX << std::endl;
    
    
    std::cout << "vMid = " << std::endl;
    std::cout << vMid << std::endl;
    
    std::cout<< "LAT_CON =" << std::endl;
    std::cout<<L.m_coordinates[LAT_CON]<<std::endl;
    std::cout<< "MED_CON =" << std::endl;
    std::cout<<L.m_coordinates[MED_CON]<<std::endl;
    
}

void Cluster::createTAxsis()
{
        std::cout << "createTAxis" << std::endl;
    CPPL::dcovector vMid(3);
    CPPL::dcovector vMid2(3);
    CPPL::dcovector vS(3);
    CPPL::dcovector vX(3);
    CPPL::dcovector vY(3);
    CPPL::dcovector vZ(3);
    
    vMid=(L.m_coordinates[MED_MALL]+L.m_coordinates[LAT_MALL])/2.0;
    vMid2=vMid;
    
    vMid2(1) = vY(1);
    
    vS=L.m_coordinates[LAT_MALL];
    vX=L.m_coordinates[MED_MALL];
    vY=L.m_coordinates[TA1];
    
    vY -= vS;
    vZ = cross(vX, vY);
    vX = cross(vZ, vY);
    
    vS -= vMid2;
    vX -= vMid2;
    vY -= vMid2;
    vZ -= vMid2;
    
    std::cout << "posS = " << std::endl;
    std::cout << vS << std::endl;
    
    std::cout << "vecY = " << std::endl;
    std::cout << vY<< std::endl;
    std::cout << "vecZ = " << std::endl;
    std::cout << vZ << std::endl;    
    std::cout << "vecX = " << std::endl;
    std::cout << vX << std::endl;
    
    std::cout << "vMid2 = " << std::endl;
    std::cout << vMid2 << std::endl;
    
    std::cout<< "TA1 =" << std::endl;
    std::cout<<L.m_coordinates[TA1]<<std::endl;
    
    std::cout<< "LAT_MALL =" << std::endl;
    std::cout<<L.m_coordinates[LAT_MALL]<<std::endl;
    std::cout<< "MED_MALL =" << std::endl;
    std::cout<<L.m_coordinates[MED_MALL]<<std::endl;

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
