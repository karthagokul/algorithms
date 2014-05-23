#include <iostream>
#include <stdlib.h>

using namespace std;

void randomIntGenerator(int *aArray,int aSize)
{
    srand (time(NULL));
    for(int i=0;i<aSize;i++)
    {
        aArray[i]=i+(rand()%(aSize*2));
    }
}

void printArray(int *aArray,int aSize)
{
    cout<<endl;
    for(int i=0;i<aSize;i++)
    {
        cout<<aArray[i]<<"\t";
    }
    cout<<endl;
}

void selectionsort(int *aArray,int aSize)
{
    cout<<"come";
    int min,i,j;
    for(i=0;i<aSize-1;i++)
    {
        min=i;
        for(j=i+1;j<aSize;j++)
        {
            if(aArray[min]>aArray[j])
            {
                min=j;
            }

        }
        if(min!=i)
        {
            int tmp=aArray[i];
            aArray[i]=aArray[min];
            aArray[min]=tmp;
        }

        printArray(aArray,aSize);
    }
}


int main()
{
    int *array=NULL;
    int size;
    //cout<<"Enter the number of elements";
    //cin>>size;
    size=5;
    array=new int[size];

    randomIntGenerator(array,size);
    cout<<endl<<"Original Array";
    printArray(array,size);

    selectionsort(array,size);

    cout<<endl<<"Sorted Array";
    printArray(array,size);

    delete [] array;
    array=NULL;

    return 0;
}
