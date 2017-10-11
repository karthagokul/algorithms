#include <iostream>

void printArray(int a[],int start,int stop)
{
    std::cout<<"{ ";
    for(int i=start;i<stop;i++)
    {
        std::cout<<a[i]<<",";
    }
    std::cout<<" }"<<std::endl;
}

int main() {
    int a[]={23,42,4,16,8,15};
    int count=6;
    printArray(a,0,6);

    //selection sort

    //Lets select the first item as the minimum, assumption
    int minimum,i,j;
    for( i=0;i<count-1;i++) //go from 0 to the second last
    {
        minimum=i;
        for( j=i+1;j<count;j++)//inner loop to start from next item
        {
            if(a[minimum]>a[j]) //check for small number
            {
                minimum=j;
            }
        }
        if(i!=minimum) //see if minimum got reset then swap
        {
            std::cout<<"Swapped ";
            int swp=a[minimum];
            a[minimum]=a[i];
            a[i]=swp;
        }
        printArray(a,0,6);
    }
    return 0;
}