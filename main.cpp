#include <iostream>
#include <vector>
#include "mrStd.hpp"
#include "pct.hpp"


void motionCaputure(GrCoord mrkrF, GrCoord mrkrT)
{
//ここに処理書く
}
void pct (GrCoord mrkr, Cluster c)
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


