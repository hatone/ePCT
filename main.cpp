/*!
 *  \file  main.cpp
 *  \brief 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <cpplapack/cpplapack.h>
#pragma comment(lib, "BLAS.lib")
#pragma comment(lib, "clapack.lib")
#pragma comment(lib, "libf2c.lib")

#include "levmar.h"

#include "pct.hpp"

const std::string fileName("t0.txt");

void display(Cluster f, Cluster t)
{
    //ここに処理書く
}

void display(GrCoord &mrkr)
{
    printf("(     x,     y,     z,     m)\n");
    for (size_t i = 0; i < mrkr.m_coordinates.size(); i++)
    {
        printf("( %3.3lf, %3.3lf, %3.3lf, %3.3lf)\n",
               mrkr.m_coordinates[i](0), mrkr.m_coordinates[i](1), mrkr.m_coordinates[i](2), mrkr.m_mass[i]);
    }
}

void display(std::vector<CPPL::dcovector> v)
{
    printf("(     x,     y,     z)\n");
    for (size_t i = 0; i < v.size(); i++)
    {
        printf("( %3.3lf, %3.3lf, %3.3lf)\n",
               v[i](0), v[i](1), v[i](2));
    }
}

void motionCaputure(GrCoord &mrkrF, GrCoord &mrkrT)
{
    // そのうち読み込みをモーションキャプチャに合わせないとね
    
    // 適当なグローバル座標群を作成
    std::ifstream fin(fileName.c_str());
    GrCoord *p_crrnt;
    int size = 4;
    
    for (int i = 0; i < 2; i++)
    {
        switch (i)
        {
            case 0:
                p_crrnt = &mrkrF;
                break;
            case 1:
                p_crrnt = &mrkrT;
                break;
        }
        
        p_crrnt->m_coordinates.reserve(size);
        p_crrnt->m_mass.reserve(size);
        for (int i = 0; i < size && !fin.eof(); i++)
        {
            std::string buf;
            fin >> buf;
            
            boost::tokenizer<> tk(buf);
            
            for (boost::tokenizer<>::iterator it = tk.begin(); it != tk.end();)
            {
                CPPL::dcovector v(3);
                
                v(0) = boost::lexical_cast<double>(*it++);
                v(1) = boost::lexical_cast<double>(*it++);
                v(2) = boost::lexical_cast<double>(*it++);
                
                p_crrnt->m_coordinates.push_back(v);
                p_crrnt->m_mass.push_back(boost::lexical_cast<double>(*it++));
            }
        }
    }
    fin.close();
}

int main(int argc, char *argv[])
{
	Cluster k_f,k_t;
    Cluster f, t;
    
    
	motionCaputure(f.G, t.G);
    display(f.G);
    display(t.G);
    
    f.pct();
    std::cout << "==========================" << std::endl;
	t.pct();
    
    //とりあえず今だけ。1回だけ実行したい。
    k_f = f;
    k_t = t;
    
    f.redistributionMass(k_f);
    
    
    //   display(f, t);
    //   
    return 0;
}
