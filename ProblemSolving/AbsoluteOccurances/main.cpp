#include <iostream>
#include <unordered_set>

using namespace std;

int unique_numbers(int A[])
{
    std::unordered_set<int>set;
    for(int i=0;i<sizeof(A);i++)
    {
        set.insert(abs(A[i]));
    }
    return set.size();
}

int main()
{
    int A[]={-1,0,1,2};
    std::cout<<unique_numbers(A);
    return 0;
}

