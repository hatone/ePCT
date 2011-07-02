/*!
 *  \file  pct.cpp
 *  \brief 
 */
#include "pct.hpp"

Cluster::Cluster()
{
    pos.resize(3);
    cm.resize(3);
}

Cluster::~Cluster()
{
}

void Cluster::createLocalCoordinates(CPPL::dcovector &wFact, std::vector<CPPL::dcovector> &vr)
{
    CPPL::dgematrix R(3,3);
    CPPL::dgematrix tR;//転置行列
    
    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            R(j,i)=vr[i](j);
        }
    }
    
    tR= CPPL::t(R);
    
    L.m_coordinates.resize(G.m_coordinates.size());
    

    
    for(size_t i=0; i< G.m_coordinates.size(); i++)
    {
        L.m_coordinates[i]=tR*(G.m_coordinates[i]-wFact);
    }
    
}

/*!
 *  \brief éøó èdêS
 *  \param coordinates[out] ÉOÉçÅ[ÉoÉãç¿ïWåQ, masséøó åQ
 */
void GrCoord::weightFactor(CPPL::dcovector &C)
{
    CPPL::dcovector gm(3);
    double m = 0.0;
    
    for(size_t i = 0; i < m_coordinates.size(); i++)
    {
        m += m_mass[i];
        gm += m_coordinates[i]*m_mass[i];
    }
    
    C = gm * (1.0/m);
}
