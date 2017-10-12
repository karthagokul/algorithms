#include "linearsort.h"

LinearSort::LinearSort()
{
}

bool LinearSort::sort()
{
    for(int i=0;i<count;i++)
    {
        for(int j=i;j<count;j++)
        {
            if(array[j]>array[i])
            {
                int temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
    return true;
}
