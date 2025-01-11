#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctype.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if (!isalnum(s[start]))
                start++;
            else if (!isalnum(s[end]))
                end--;
            else if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++; 
                end--;
            }
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    cout << sol.isPalindrome(s);
    return 0;
}