//A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

//For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.


#include <iostream>

using namespace std;

int solution(int N) {
    int count=0;
    int tempcount=-1;
    int curstore=0,prevstore=0;
    while(N>0)
    {
        curstore=N%2;
        cout<<curstore;
        N=N/2;
        if(curstore==1)
        {
            prevstore=curstore;
            if(count<tempcount)
            {
                count=tempcount;
            }
            tempcount=0;
        }
        else
        {
            if(tempcount!=-1)
            tempcount++;
        }
    }
    cout<<endl;
    return count;
}

int main()
{
    int N=147483647;
    cout<<solution(N)<<endl;
    return 0;
}
