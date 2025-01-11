#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> results;
    void generateParenthesis(int left ,int right, string s)
    {
        if (left < 0 || right < 0) 
            return;
        if(left == 0 && right == 0)
        {
            results.push_back(s);
            return;
        }
        generateParenthesis(left - 1, right, s +"(");
        if(right > left)
            generateParenthesis(left, right - 1, s + ")");
    }

    void startGeneration(int n)
    {
        generateParenthesis(n, n, "");
    }

    void printVector()
    {
        for (vector<string>::iterator t=results.begin(); t!=results.end(); ++t) 
        {
            cout<<*t<<endl;
        }
    }
};

int main()
{
    Solution sol;
    sol.startGeneration(3);
    sol.printVector();
}