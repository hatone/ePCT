#include <iostream>
#include <vector>
#include "mrStd.hpp"
#include "pct.hpp"


void motionCaputure(std::vector<Vec3d> mrkrF, std::vector<Vec3d> mrkrT)
{
//ここに処理書く
}
void pct (std::vector<Vec3d> mrkr, Cluster c)
{
//ここに処理書く
    std::cout<<"PCT"<<std::endl;
}
void display (Cluster f, Cluster t)
{
//ここに処理書く
}



int main(int argc, char *argv[])
{
    std::vector<Vec3d> mrkrF, mrkrT;  
	Cluster f, t;
    
	motionCaputure(mrkrF, mrkrT);
    pct(mrkrF, f);    
	pct(mrkrT, t);
    display(f, t);
	
	std::cout << "yeah!!!!!!!!!!" << std::endl;
	std::cout << "nuha-!!!!!!!!!" << std::endl;
	
    return 0;

}


