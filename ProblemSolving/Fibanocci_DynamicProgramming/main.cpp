#include <iostream>
#include <vector>

using namespace std;

/**
 * Fabinocii Numbers usingDynamic Programming.
 */

std::vector<int> data;

int fib(int n)
{
    if((n==0)||(n==1))
    {
        data[n]=n;
    }
    else
    {
        data[n]=(fib(n-1)+fib(n-2));
    }
    return data[n];
}

int solution(int n)
{
    data.resize(n);
    std:cout<<fib(n)<<std::endl;
    return 0;
}

int main()
{
    solution(9);
    return 0;
}

