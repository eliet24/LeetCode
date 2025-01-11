#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        char digit = '+';
        while (s[i] != '\0')
        {
            if(p[j] == '\0')
                return false;
            if(p[j] != '*' && p[j] != '.')
            {
                digit = p[j];
                if (s[i] != p[j]){
                    return false;
                }
                i++;
                j++;
            }
            else if(p[j] == '*' || digit != '+'){
                if(digit == '.'){
                    if(p[j+1] == '\0')
                        return true;
                }
                if(s[i] == digit)
                    i++;
                else{
                    j++;
                }
            }
            else if(p[j] == '.' || digit != '+'){
                digit = '.';
                i++;
                j++;
            }
        }
        return true;
    }
};



int main()
{
    Solution sol;
    string s = "aaa";
    string p = "a.*";
    string a = "aa";
    string b = "a";
    string c = "aa";
    string d = "aa";
    string e = "ab";
    string f = ".*";
    cout << s << ", " << p << " : " << sol.isMatch(s,p) << endl;
    cout << a << ", " << b << " : " << sol.isMatch(a,b) << endl;
    cout << c << ", " << d << " : " << sol.isMatch(c,d) << endl;
    cout << e << ", " << f << " : " << sol.isMatch(e,f) << endl;
    return 0;
}