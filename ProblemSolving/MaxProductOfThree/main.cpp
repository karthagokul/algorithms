/*
 * 
  */
#include <iostream>
#include <vector>
#include <algorithm>
#include<vector>
#include <limits>
using namespace std;



int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int leftMost = std::numeric_limits<int>::min(); // minimum value
    int rightMost = std::numeric_limits<int>::max();

   vector<int> ref=A;
   std::sort(ref.begin(),ref.end());
   for(int i=0;i<ref.size();i++)
   std::cout<<ref[i]<<",";
   std::cout<<std::endl;

   if(ref.size()<3)return 0;

   int P=ref[ref.size()-1];
   int Q=ref[ref.size()-2];
   int R=ref[ref.size()-3];
   rightMost=P*Q*R;

   P=ref[0];
   Q=ref[1];
   R=ref[2];
   leftMost=P*Q*R;

   return (rightMost>leftMost)?rightMost:leftMost;
}

int main()
{
    //After sorting, 1,1,2,3,4,6
    vector<int> A{-3, 1, 2, -2, 5, 6,-1,-1,2,3,0};
    std::cout<<"Tripplest Number is "<<solution(A)<<std::endl;
    return 0;
}

