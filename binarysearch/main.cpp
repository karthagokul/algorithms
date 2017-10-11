#include <iostream>

/* Long2(n) Complexity
 * Array is sorted
 * Array is [10,24,32,54,57,78,83,84,85,92] and Size of 10
 * We are searching for 85
 * 57>85 , No , StartIndex=MidIndex, StopIndexRemains Same
 * Now Aray is 78,83,84,85,92
 * 83>85 No StartIndex=MidIndex, StopIndexRemains Same
 * Now Array is 84,85,92
 *  *
 *  Points to Consider
 *    An Item which is not present in the array
 *    Repetitive Elements in the Array which is sorted
 */

void print(int a[],int startIndex,int stopIndex)
{
    for(int i=startIndex;i<stopIndex;i++)
    {
        std::cout<<a[i]<<",";
    }
    std::cout<<std::endl;
}

int binarySearch(int a[],int aStopIndex,int sv)
{
   // int index=0;
    int startIndex=0;
    int stopIndex=aStopIndex;
    while(startIndex<stopIndex)
    {
        std::cout<<std::endl<<"Array : ";
        print(a,startIndex,aStopIndex);

        int midIndex=(startIndex+stopIndex)/2;
        if(a[midIndex]>sv)
        {
            std::cout<<"Picking " << a[midIndex]<< " is > "<<sv;
            stopIndex=midIndex;
        }
        else if(a[midIndex]==sv)
        {
            std::cout<<"Picking " << a[midIndex]<< " is == "<<sv;
            return midIndex;
        }
        else
        {
            std::cout<<"Picking " << a[midIndex]<< " is < "<<sv;
            startIndex=midIndex+1;
        }
        std::cout<<" Start Index:"<<startIndex<<",Stop Index:"<<stopIndex;
    }
    return -1;
}

int main() {
    int a[]={10,24,32,54,57,78,83,84,85,92};
    const int arraySize=10;
    const int searchValue=100;
    int index=binarySearch(a,arraySize,searchValue);
    if(index!=-1)
        std::cout<<std::endl<<"The Index of "<<searchValue<<" is "<<index;
    else
        std::cout<<std::endl<<"The "<<searchValue<<" is not in the array";
    std::cout<<std::endl;
    return 0;
}