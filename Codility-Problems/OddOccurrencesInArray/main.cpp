/*
 * A non-empty zero-indexed array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Assume that:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

Copyright 2009–2017 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_map<int, int> letter_counts;

    for(size_t i=0;i<A.size();i++)
    {
        if(letter_counts.find(A[i])==letter_counts.end())
        {
            //create new
            letter_counts[A[i]]=1;
        }
        else
        {
            int value=letter_counts.at(A[i]);
            letter_counts[A[i]]=value+1;
        }
        //std::cout<<letter_counts.at(A[i])<<std::endl;
    }

    int occurance=-1;
    for (const auto &pair : letter_counts) {
        if(pair.second%2!=0)
        {
            occurance=pair.first;
        }
    }
    return occurance;
}

int main()
{
    std::vector<int> v{3,9,2,9,3};
    std::cout<<solution(v);
    return 0;
}
