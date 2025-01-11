#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        return search(0, n);
    }

    int search(int curr, int n)
    {
        if (curr == n)
            return 1;
        else if (curr > n)
            return 0;
        else
            return search(curr + 1, n) + search(curr + 2, n);
    }

    int climbStairsDP(int n)
    {
        if (n <= 2)
            return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(2) << endl;
    cout << sol.climbStairs(3) << endl;
    cout << sol.climbStairs(4) << endl;
    cout << sol.climbStairsDP(2) << endl;
    cout << sol.climbStairsDP(3) << endl;
    cout << sol.climbStairsDP(4) << endl;
    cout << sol.climbStairsDP(44) << endl;
    return 0;
}