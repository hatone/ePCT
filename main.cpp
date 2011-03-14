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
    
    // 適当なグローバル座標群を作成
    std::vector<Vec3d> coordinates;
    int size = 10;
    coordinates.reserve(size);
    for (int i = 0; i < size; i++)
    {
        Vec3d v(i, i+1, i+2);
        coordinates.push_back(v);
        
        std::cout<< v.x << std::endl;
    }
    
    // グローバル座標群を代入
    mrkr.setCoord(coordinates);
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
	
	std::cout << "yeah!!!!!!!!!!" << std::endl;
	std::cout << "nuha-!!!!!!!!!" << std::endl;
	
    return 0;

}


