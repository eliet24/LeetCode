#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.length() <= 0 || p.length() >= 2000)
            return false;
        bool dp_table[s.length() + 1][p.length() + 1];
        memset(dp_table, 0, sizeof(dp_table));
        dp_table[0][0] = 1;
        for (int i = 1; i <= p.length(); i++)
        {
            dp_table[0][i] = (p[i - 1] == '*' && dp_table[0][i - 1]);
        }
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= p.length(); j++)
            {
                if (p[j - 1] != '*')
                {
                    if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    {
                        dp_table[i][j] = dp_table[i - 1][j - 1];
                    }
                }
                else
                {
                    dp_table[i][j] = dp_table[i][j - 1] || dp_table[i - 1][j];
                }
            }
        }
        return dp_table[s.length()][p.length()];
    }
};

int main()
{
    Solution sol;
    cout <<sol.isMatch("aa", "a")<<endl;
    cout << sol.isMatch("aa", "*") << endl;
    cout << sol.isMatch("cb", "?a") << endl;
    return 0;
}
