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

void Cluster::createLocalCoordinates(std::vector<CPPL::dcovector> &L, CPPL::dcovector &wFact, std::vector<CPPL::dcovector> &vr)
{
}

/*!
 *  \brief ���ʏd�S
 *  \param coordinates[out] �O���[�o�����W�Q, mass���ʌQ
 */
void GrCoord::weightFactor(CPPL::dcovector &C)
{
    CPPL::dcovector gm;
    double m = 0.0;
        
    for(size_t i = 0; i < m_coordinates.size(); i++)
    {
        m += m_mass[i];
        gm += m_coordinates[i]*m_mass[i];
    }
    C = gm * (1.0/m);
}
