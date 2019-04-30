#include <iostream>
#include <future>
#include <unistd.h>

using namespace std;

//std::async is a high level abstraction of std::thread

int Computing_One()
{
    for(int i=0;i<10;i++)
    {
        std::cout<<"One: "<<i<<std::endl;
        sleep(1);
    }
    return 1;
}

int Computing_Two()
{
    for(int i=0;i<10;i++)
    {
        std::cout<<"Two: "<<i<<std::endl;
        sleep(1);
    }
    return 2;
}

int main()
{
    std::future<int> compute_one_result=std::async(Computing_One);
    std::future<int> compute_two_result=std::async(Computing_Two);
    std::cout<<"Main Function"<<std::endl;
    std::cout<<compute_one_result.get()<<std::endl;
    std::cout<<compute_two_result.get()<<std::endl;
    return 0;
}
