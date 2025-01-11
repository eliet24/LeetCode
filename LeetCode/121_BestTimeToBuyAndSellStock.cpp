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
        int max_profit = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < lsf)
                lsf = prices[i];
            profit = prices[i] - lsf;
            if(profit > max_profit)
                max_profit = profit;
        }
        return max_profit;
    }
};