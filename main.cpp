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

const int MARKER_NUM = 23;
const std::string fileName("s1c1.tsv");

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

    std::ifstream fin(fileName);
    std::string buf;

    for (int i = 0; i < MARKER_NUM; i++)
    {
        CPPL::dcovector v(3);
        double d;
        fin >> d;
        v(0) = boost::lexical_cast<double>(d);
        fin >> d;
        v(2) = boost::lexical_cast<double>(d);
        fin >> d;
        v(1) = boost::lexical_cast<double>(d);



        //for (int j = 0; j < 3; j++)
        //{
        //    fin >> d;
        //    v(j) = boost::lexical_cast<double>(d);
        //}
        switch (i)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 15:
            case 16:
            case 17:
                mrkrF.m_coordinates.push_back(v);
                mrkrF.m_mass.push_back(1.0);
                break;
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
                mrkrT.m_coordinates.push_back(v);
                mrkrT.m_mass.push_back(1.0);
                break;
        }
    }

    //std::ifstream fin(fileName.c_str());
    //for (int i = 0; !fin.eof(); i++)
    //{
    //    std::cout<<"i "<<i<<std::endl;
    //    std::string buf;
    //    fin >> buf;
    //    std::cout<<"buf "<<buf<<std::endl;
    //    
    //    boost::char_separator<char> dl(",");
    //    
    //
    //    boost::tokenizer<boost::char_separator<char> > tk(buf, dl);
    //        
    //    boost::tokenizer<boost::char_separator<char> >::iterator it = tk.begin();
    //    CPPL::dcovector v(3);

    //    v(0) = boost::lexical_cast<double>(*it++);
    //    v(1) = boost::lexical_cast<double>(*it++);
    //    v(2) = boost::lexical_cast<double>(*it++);

    //    switch (i)
    //    {
    //    case 0:
    //    case 1:
    //    case 2:
    //    case 3:
    //    case 4:
    //    case 5:
    //    case 6:
    //    case 7:
    //    case 8:
    //    case 15:
    //    case 16:
    //    case 17:
    //        mrkrF.m_coordinates.push_back(v);
    //        mrkrF.m_mass.push_back(1.0);
    //        break;
    //    case 9:
    //    case 10:
    //    case 11:
    //    case 12:
    //    case 13:
    //    case 14:
    //    case 18:
    //    case 19:
    //    case 20:
    //    case 21:
    //    case 22:
    //        mrkrT.m_coordinates.push_back(v);
    //        mrkrT.m_mass.push_back(1.0);
    //        break;
    //    }
    //}

}

int main(int argc, char *argv[])
{
	Cluster k_f,k_t;
    Cluster f, t;
    
    
	motionCaputure(f.G, t.G);

    display(f.G);
    display(t.G);

    return 0;

    f.pct();
    std::cout << "==========================" << std::endl;
	t.pct();
    
    //とりあえず今だけ。1回だけ実行したい。
    k_f = f;
    k_t = t;
    
    f.redistributionMass(k_f);
    t.redistributionMass(k_t);
    
    //   display(f, t);
    //   
    return 0;
}
