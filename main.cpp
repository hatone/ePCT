#include <iostream>
#include <fstream>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <cpplapack/cpplapack.h>
//#include <cpplapack.h>
#pragma comment(lib, "BLAS.lib")
#pragma comment(lib, "clapack.lib")
#pragma comment(lib, "libf2c.lib")

#include "levmar.h"
#include "mrStd.hpp"
#include "pct.hpp"

const std::string fileName("t0.txt");

void display(Cluster f, Cluster t)
{
    //ここに処理書く
}

void display(GrCoord &mrkr)
{
    printf("(     x,     y,     z,     m)\n");
    for (unsigned int i = 0; i < mrkr.m_coordinates.size(); i++)
    {
        printf("( %3.3lf, %3.3lf, %3.3lf, %3.3lf)\n",
            mrkr.m_coordinates[i].x, mrkr.m_coordinates[i].y, mrkr.m_coordinates[i].z, mrkr.m_mass[i]);
    }
}

void display(std::vector<Vec3d> v)
{
    printf("(     x,     y,     z)\n");
    for (unsigned int i = 0; i < v.size(); i++)
    {
        printf("( %3.3lf, %3.3lf, %3.3lf)\n",
            v[i].x, v[i].y, v[i].z);
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
                Vec3d v;
                v.x = boost::lexical_cast<double>(*it++);
                v.y = boost::lexical_cast<double>(*it++);
                v.z = boost::lexical_cast<double>(*it++);
                p_crrnt->m_coordinates.push_back(v);
                p_crrnt->m_mass.push_back(boost::lexical_cast<double>(*it++));
            }
        }
    }
    fin.close();
}
void pct(Cluster c)
{
    //ここに処理書く
    std::cout<<"PCT"<<std::endl;
    Vec3d wFact;//質量重心
    std::vector<Vec3d> p;//慣性テンソル行列を生成するためのP(t)i
    CPPL::dgematrix tI(3, 3); //慣性テンソル行列I(t)
    
    //質量重心算出
    c.G.weightFactor(wFact);
    std::cout << "C(t): " << wFact.x << ", " << wFact.y << ", " << wFact.z << std::endl;
    
    //慣性テンソル行列生成
    c.G.createP(wFact, p);

    std::cout << "P = " << std::endl;
    display(p);

    c.G.createTensor(tI);

    //慣性テンソル行列の固有と算出
    std::vector<double> wr, wi; //固有値 実数wr 虚数wi
    std::vector<CPPL::dcovector> vr, vi;//固有ベクトル 実数vr 虚数vi
    tI.dgeev(wr,wi,vr,vi);  //いでよ固有値！固有ベクトル！！
    
 

    //std::cout << vr[0].array[0] << vr[0].array[1] << vr[0].array[2] << std::endl;
    
    //表示系
    for(int i=0; i<3; i++){
        std::cout << "#### " << i << "th eigen ####" << std::endl;
        std::cout << "wr=" << wr[i] << std::endl;
        std::cout << "vr=\n" << vr[i] << std::endl;
    }
    
    

    std::cout<<wFact.x<<wFact.y<<wFact.z<<std::endl;
    std::cout<<p[0].x<<p[1].y<<p[2].z<<std::endl;
    std::cout<<tI<<std::endl;
    
    std::vector<CPPL::dcovector> L;
    c.G.createLocal(L, wFact, vr);
    
    
}

int main(int argc, char *argv[])
{
	Cluster f, t;
    
	motionCaputure(f.G, t.G);
    display(f.G);
    display(t.G);

    pct(f);
	pct(t);
    display(f, t);
    
    return 0;
}
