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
    vector<vector<int>> subsets_it(vector<int> &nums)
    {
        vector<vector<int>> res={{}};
        for(int num:nums)
        {
            int n =res.size();
            for(int i = 0; i < n; i++)
            {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
        vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums,0,sub,subs);
        return subs;
    }
    void subsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs)
    {
        subs.push_back(sub);
        for(int j = i; j < nums.size(); j++)
        {
        sub.push_back(nums[j]);
        subsets(nums, i + 1, sub, subs);
        sub.pop_back();
        }
    }
};

int main()
{
    vector<int> vec1 = {1,2,3};
    Solution sol;
    //sol.subsets_it(vec1);
    sol.subsets(vec1);
    return 0;
}