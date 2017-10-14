/*
 * A non-empty zero-indexed array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);
that, given a non-empty zero-indexed array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Assume that:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Complexity:

expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
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

