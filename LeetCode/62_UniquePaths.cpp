#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int uniquePathsDP(int m, int n) //dynamic programming approach
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (n == 1 || m == 1)
            return 1;
        for (int i = 1; i < m; i++)
            dp[i][0] = 1;
        for (int j = 1; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsRecu(int m, int n)
    {
        if (m <= 1 && n <= 1)
            return 1;
        else
        {
            // return countPathBack(m-1, n-1);
            return countPath(1, 1, m, n);
        }
    }

    int countPathBack(int i, int j) // backward recursion approach
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        return countPathBack(i - 1, j) + countPathBack(i, j - 1);
    }

    int countPath(int i, int j, int m, int n) // forward recursion approach
    {
        if (i == m && j == n)
            return 1;
        if (i > m || j > n)
            return 0;
        return countPath(i + 1, j, m, n) + countPath(i, j + 1, m, n);
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePathsRecu(3, 7) << endl;
    cout << sol.uniquePathsRecu(3, 2) << endl;
    cout << sol.uniquePathsDP(3, 7) << endl;
    cout << sol.uniquePathsDP(3, 2) << endl;
    return 0;
}