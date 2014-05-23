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
  //2 6 1 3 4 5
  //2 6 1 3 4 5
  //2 1 6 3 4 5
  //1 2 3 6 4 5
  //1 2 3 4 6 5
  //1 2 3 4 5 6

  int swp;
  for(int i=0;i<aSize-1;i++)
  {
      for(int j=1;j<aSize;j++)
      {
          if(aArray[j-1]>aArray[j])
          {
              swp=aArray[j-1];
              aArray[j-1]=aArray[j];
              aArray[j]=swp;
          }
      }
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
    cout<<"Original Array"<<endl;
    printArray(array,size);

    bubblesort(array,size);

    cout<<"Sorted Array"<<endl;
    printArray(array,size);

    delete [] array;
    array=NULL;

    return 0;
}
