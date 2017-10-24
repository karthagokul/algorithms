#include <iostream>

using namespace std;

const int MAP_WIDTH=640;
const int MAP_HEIGHT=480;

void convertLongLatToXY(double longitude,double latitude ,int &x,int &y)
{
    x =  (int) ((MAP_WIDTH/360.0) * (180 + longitude));
    y =  (int) ((MAP_HEIGHT/180.0) * (90 - latitude));
    std::cout<<"(Longitude,Latitude)=( "<<longitude<<","<<latitude<<" )-> "<<"(X,Y)=( "<<x<<","<<y<<" )";
    std::cout<<std::endl;
    return;
}

int main()
{
    int x=0,y=0;
    convertLongLatToXY(127.968750,-24.297040,x,y);
    convertLongLatToXY(17.037692,18.898648,x,y);
    convertLongLatToXY(76.992188,21.197216,x,y);
    return 0;
}

