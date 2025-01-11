#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 1);
        for (int i = 2; i < s.size() + 1; i++)
        {
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];
            else
                dp[i] = 0;
            if (s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26)
                dp[i] = dp[i] + dp[i - 2];
            else
                dp[i] = dp[i] + 0;
        }
        return dp[s.size()];
    }
};

int mian()
{
    Solution sol;
    cout << sol.numDecodings("226") << endl;
    return 0;
}