#include <iostream>
#include <vector>
#include "mrStd.hpp"


void (std::vector<Vec3i> mrkrF, std::vector<Vec3i> mrkrT)
{
//ここに処理書く
}
void pct (std::vector<Vec3i> mrkrF, Vec3i mrkrT)
{
//ここに処理書く
}
void display (Vec3i mrkrF, Vec3i mrkrT)
{
//ここに処理書く
}



int main(int argc, char *argv[]){
    std::vector<Vec3i> mrkrF, mrkrT;  
//	Cluster f, t;　//ここどうしよう
	
	Vec3i f,t;
	motionCaputure(mrkrF, mrkrT);
    pct(mrkrF, f);    
	pct(mrkrT, t);
    display(f, t);
    return 0;}


