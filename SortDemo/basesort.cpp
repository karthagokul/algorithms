#include "basesort.h"
#include <iostream>

int BaseSort::array[]={10,20,30,40,50,60,70,80,90,100};

BaseSort::BaseSort()
{
}

void BaseSort::print()
{
    for(int i=0;i<count;i++)
    {
        std::cout<<array[i]<<",";
    }
    std::cout<<std::endl;
}

