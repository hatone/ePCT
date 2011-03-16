#include <iostream>
#include <vector>
#include "mrStd.hpp"
#include "pct.hpp"
#include <cpplapack/cpplapack.h>


void motionCaputure(GrCoord mrkrF, GrCoord mrkrT)
{
    //ここに処理書く
}
void pct(GrCoord mrkr, Cluster c)
{
    //ここに処理書く
    std::cout<<"PCT"<<std::endl;
    Vec3d wFact;//質量重心
    CPPL::dgematrix tI; //慣性テンソル行列I(t)
    std::vector<Vec3d> p;//慣性テンソル行列を生成するためのP(t)i
    
    // 適当なグローバル座標群を作成
    std::vector<Vec3d> coordinates;
    std::vector<double> mass;
    int size = 3;
    coordinates.reserve(size);
    for (int i = 0; i < size; i++)
    {
        Vec3d v(i, i+1, i+2);
        coordinates.push_back(v);
        p.push_back(v);
        mass.push_back(2);
        
        std::cout<<v.x<<v.y<<v.z<<std::endl;
    }
    
    // グローバル座標群を代入
    mrkr.setCoord(coordinates);
    
    //質量重心算出
    wFact=mrkr.weightFactor(coordinates,mass);
    
    //慣性テンソル行列生成
    p=mrkr.createP(coordinates,wFact,p);
    tI=mrkr.createTensor(coordinates,mass);
    
    //慣性テンソル行列の固有と算出
    std::vector<double> wr, wi; //固有値 実数wr 虚数wi
    std::vector<CPPL::dcovector> vr, vi;//固有ベクトル 実数vr 虚数vi
    tI.dggev(tI,wr,wi,vr,vi);  //いでよ固有値！固有ベクトル！！
    
    
    //表示系
    for(int i=0; i<3; i++){
        std::cout << "#### " << i << "th eigen ####" << std::endl;
        std::cout << "wr=" << wr[i] << std::endl;
        std::cout << "wi=" << wi[i] << std::endl;
        std::cout << "vr=\n" << vr[i] << std::endl;
        std::cout << "vi=\n" << vi[i] << std::endl;
    }
    
    

    std::cout<<wFact.x<<wFact.y<<wFact.z<<std::endl;
    std::cout<<p[0].x<<p[1].y<<p[2].z<<std::endl;
    std::cout<<tI<<std::endl;
    
}
void display (Cluster f, Cluster t)
{
    //ここに処理書く
}



int main(int argc, char *argv[])
{
    GrCoord mrkrF, mrkrT;  
	Cluster f, t;
    
	motionCaputure(mrkrF, mrkrT);
    pct(mrkrF, f);    
	pct(mrkrT, t);
    display(f, t);
	
	
    return 0;
    
}


