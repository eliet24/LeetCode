#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        bool exist;
        int k;
        for (int i = 0; i < haystack.size(); i++)
        {
            k = i;
            exist = true;
            if (haystack[i] == needle[0])
            {
                for (int j = 0; j < needle.size(); j++)
                {
                    if (haystack[k] != needle[j])
                    {
                        exist = false;
                    }
                    k++;
                }
                if (exist)
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    string a = "sadbutsad";
    string b = "sad";
    string c = "leetcode";
    string d = "leeto";
    string e = "leetcodetocode";
    string f = "code";
    Solution sol;
    cout << sol.strStr(a, b) << " " << sol.strStr(c, d) << " " << sol.strStr(e, f) << endl;
    return 0;
}