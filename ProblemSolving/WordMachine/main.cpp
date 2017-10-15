#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

#include <sstream>
#include <vector>
#include <stack>

bool push(stack<int> &wStack,int num)
{
    wStack.push(num);
    return true;
}

bool pop(stack<int> &wStack)
{
    if(wStack.empty())
        return false;
    wStack.pop();
    return true;
}

bool dup(stack<int> &wStack)
{
    int temp=wStack.top();
    wStack.push(temp);
    return true;
}

bool add(stack<int> &wStack)
{
    int num1=wStack.top();
    if(!pop(wStack)) return false;
    int num2=wStack.top();
    if(!pop(wStack)) return false;

    int result=num1+num2;
    push(wStack,result);
    return true;
}

bool sub(stack<int> &wStack)
{
    if(wStack.size()<3)
        return false;

    int num1=wStack.top();
    if(!pop(wStack)) return false;
    int num2=wStack.top();
    if(!pop(wStack)) return false;

    int result=num1-num2;
    push(wStack,result);
    return true;
}

/* Perform the Operation based on the commands */
bool perform(stack<int> &wStack,string &s)
{
    if(s=="DUP")
        return dup(wStack);
    else if(s=="POP")
        return pop(wStack);
    else if(s=="+")
        return add(wStack);
    else if(s=="-")
        return sub(wStack);
    else
        return push(wStack,stoi (s));
}

/* Function to Tokenize the String */
vector<string> split(string str)
{
    vector<string> strings;
    istringstream f(str);
    string s;
    while (getline(f, s, ' '))
    {
        strings.push_back(s);
    }
    return strings;
}

/* Entry Point to the Solution*/

int solution(string &s)
{
    vector<string> strings=split(s);
    stack <int> wordstack;
    for(auto i=0; i<(int)strings.size(); i++)
    {
        if(!perform(wordstack,strings[i]))
            return -1;
    }
    return wordstack.top();
}


int main()
{
    std::string s="13 13 12 - - -";

    int res=solution(s);
    std::cout <<"Result it "<<res;
    return 0;
}
