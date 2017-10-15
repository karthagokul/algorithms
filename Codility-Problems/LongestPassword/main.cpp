/*
 * You would like to set a password for a bank account. However, there are three restrictions on the format of the password:

it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
there should be an even number of letters;
there should be an odd number of digits.
You are given a string S consisting of N characters. String S can be divided into words by splitting it at, and removing, the spaces. The goal is to choose the longest word that is a valid password. You can assume that if there are K spaces in string S then there are exactly K + 1 words.

For example, given "test 5 a0A pass007 ?xy1", there are five words and three of them are valid passwords: "5", "a0A" and "pass007". Thus the longest password is "pass007" and its length is 7. Note that neither "test" nor "?xy1" is a valid password, because "?" is not an alphanumerical character and "test" contains an even number of digits (zero).

Write a function:

int solution(string &S);

that, given a non-empty string S consisting of N characters, returns the length of the longest word from the string that is a valid password. If there is no such word, your function should return −1.

For example, given S = "test 5 a0A pass007 ?xy1", your function should return 7, as explained above.

Assume that:

N is an integer within the range [1..200];
string S consists only of printable ASCII characters and spaces.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

bool hasEvenNumberOfLetters(const std::string &str)
{
    int count=0;
    for (int i=0;i<str.length();i++)
    {
        char c=str[i];
        if(!std::isdigit(c))
        {
           count++;
        }
    }
    return ((count%2==0))?true:false;
}

bool hasOddNumberOfNNumbers(const std::string &str)
{
    int count=0;
    for (int i=0;i<str.length();i++)
    {
        char c=str[i];
        if(std::isdigit(c))
        {
           count++;
        }
    }
    return ((count%2!=0))?true:false;
}

bool isAlphaNumeric(const std::string &str)
{
    return find_if(str.begin(), str.end(),
                   [](char c) { return !(isalnum(c) || (c == ' ')); }) == str.end();
}

int isValid(string &S)
{
     return (isAlphaNumeric(S) && hasEvenNumberOfLetters(S) &&hasOddNumberOfNNumbers(S))?true:false;
}

int solution(string &S) {
    int length=0;
    vector<string> strings=split(S,' ');
    for(int i=0;i<strings.size();i++)
    {
        if(isValid(strings[i]))
        {
            if(length<strings[i].length())
            {
               length=strings[i].length();
            }
        }
    }
    return (length!=0)?length:-1;
}

int main()
{
    std::string s("1 t005");
    cout << std::endl<<solution(s) << endl;
    return 0;
}

