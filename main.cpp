#include <iostream>
#include <vector>
#include "mrStd.hpp"
#include "pct.hpp"


void motionCaputure(GrCoord mrkrF, GrCoord mrkrT)
{
    //ここに処理書く
}
void pct(GrCoord mrkr, Cluster c)
{
    //ここに処理書く
    std::cout<<"PCT"<<std::endl;
    Vec3d wFact;//質量重心
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
    wFact=mrkr.weightFactor(coordinates,mass);
    std::cout<<wFact.x<<wFact.y<<wFact.z<<std::endl;
    p=mrkr.createP(coordinates,wFact,p);
    std::cout<<p[0].x<<p[1].y<<p[2].z<<std::endl;
    
    
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


