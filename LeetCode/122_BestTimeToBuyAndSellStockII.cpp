#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lsf = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            lsf = min(lsf, prices[i]);
            if (prices[i] - lsf > 0)
            {
                profit = profit + (prices[i] - lsf);
                lsf = prices[i];
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(vec);
}