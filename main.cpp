#include <iostream>
#include <vector>

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
//#include <cpplapack/cpplapack.h>
#include <cpplapack.h>
#pragma comment(lib, "BLAS.lib")
#pragma comment(lib, "clapack.lib")
#pragma comment(lib, "libf2c.lib")

#include "mrStd.hpp"
#include "pct.hpp"


const std::string fileName("t0.txt");

void motionCaputure(GrCoord &mrkrF, GrCoord &mrkrT)
{
    // そのうち読み込みをモーションキャプチャに合わせないとね

    // 適当なグローバル座標群を作成
    std::ifstream fin(fileName);
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
void pct(GrCoord mrkr, Cluster c)
{
    //ここに処理書く
    std::cout<<"PCT"<<std::endl;
    Vec3d C;//質量重心
    std::vector<Vec3d> p;//慣性テンソル行列を生成するためのP(t)i
    CPPL::dgematrix tI; //慣性テンソル行列I(t)
    
    //質量重心算出
    mrkr.weightFactor(C);
    std::cout << "C(t): " << C.x << ", " << C.y << ", " << C.z << std::endl;
    
    ////慣性テンソル行列生成
    //mrkr.createP(coordinates,wFact,p);
    //tI=mrkr.createTensor(coordinates,mass);
    //
    ////慣性テンソル行列の固有と算出
    //std::vector<double> wr, wi; //固有値 実数wr 虚数wi
    //std::vector<CPPL::dcovector> vr, vi;//固有ベクトル 実数vr 虚数vi
    //tI.dggev(tI,wr,wi,vr,vi);  //いでよ固有値！固有ベクトル！！
    //
    //
    ////表示系
    //for(int i=0; i<3; i++){
    //    std::cout << "#### " << i << "th eigen ####" << std::endl;
    //    std::cout << "wr=" << wr[i] << std::endl;
    //    std::cout << "wi=" << wi[i] << std::endl;
    //    std::cout << "vr=\n" << vr[i] << std::endl;
    //    std::cout << "vi=\n" << vi[i] << std::endl;
    //}
    //
    //

    //std::cout<<wFact.x<<wFact.y<<wFact.z<<std::endl;
    //std::cout<<p[0].x<<p[1].y<<p[2].z<<std::endl;
    //std::cout<<tI<<std::endl;
    
}
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


int main(int argc, char *argv[])
{
 //   GrCoord mrkrF, mrkrT;  
	//Cluster f, t;
 //   
	//motionCaputure(mrkrF, mrkrT);
 //   display(mrkrF);
 //   display(mrkrT);

 //   pct(mrkrF, f);
	////pct(mrkrT, t);
 //   display(f, t);

    Vec3d v(1.0, 2.0, 3.0);
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
    v = v * 2.0;
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
    v *= 3;
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;

    return 0;
    
}


