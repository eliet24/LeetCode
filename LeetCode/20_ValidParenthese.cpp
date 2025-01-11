#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                stk.push(')');
            else if (s[i] == '[')
                stk.push(']');
            else if (s[i] == '{')
                stk.push('}');
            else
            {
                if (stk.top() != s[i])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution sol;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";
    cout << sol.isValid(s1) << " " << sol.isValid(s2) << " " << sol.isValid(s3) << " " << sol.isValid(s4) << " " << sol.isValid(s5) << endl;

    return 0; 
}