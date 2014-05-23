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

void bubblesort(int *aArray,int aSize)
{
  int swp;
  for(int i=0;i<aSize-1;i++)
  {
      for(int j=1;j<aSize;j++) //after the first pass larget number in the array will get its proper position
      {
          if(aArray[j-1]>aArray[j])
          {
              swp=aArray[j-1];
              aArray[j-1]=aArray[j];
              aArray[j]=swp;
          }
      }
      //printArray(aArray,aSize);
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

    bubblesort(array,size);

    cout<<endl<<"Sorted Array";
    printArray(array,size);

    delete [] array;
    array=NULL;

    return 0;
}
