#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxSubArrayBrute(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int maxlen = 0;
        int curr_sum;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                curr_sum += nums[j];
                max_sum = max(max_sum, curr_sum);
            }
        }
        return max_sum;
    }

    int maxSubArrayDP(vector<int> &nums)
    {
        vector<int> sums(nums);
        for (int i = 1; i < nums.size(); i++)
        {
            sums[i] = max(nums[i], nums[i] + sums[i - 1]);
        }
        return *max_element(begin(sums), end(sums));
    }

    int maxSubArrayDC(vector<int> nums)
    {
        return findMax(nums, 0, nums.size() - 1);
    }

    int findMax(vector<int> &nums, int l, int r)
    {
        int left_sum = 0;
        int right_sum = 0;
        int cur_sum;
        if (l > r)
            return INT_MIN;
        int mid = (l + r) / 2;
        cur_sum = 0;
        for (int i = mid - 1; i >= l; i--)
        {
            cur_sum += nums[i];
            left_sum = max(cur_sum, left_sum);
        }
        cur_sum = 0;
        for (int i = mid + 1; i <= r; i++)
        {
            cur_sum += nums[i];
            right_sum = max(cur_sum, right_sum);
        }
        return max({findMax(nums, l, mid - 1), findMax(nums, mid + 1, r), left_sum + nums[mid] + right_sum});
    }
};

int main()
{
    Solution sol;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    vector <int> b ={1};
    vector<int> c = {5,4,-1,7,8};
    cout<<sol.maxSubArrayBrute(a)<<endl;
    cout<<sol.maxSubArrayBrute(b)<<endl;
    cout<<sol.maxSubArrayBrute(c)<<endl;
    cout<<sol.maxSubArrayDC(a)<<endl;
    cout<<sol.maxSubArrayDC(b)<<endl;
    cout<<sol.maxSubArrayDC(c)<<endl;
    cout<<sol.maxSubArrayDP(a)<<endl;
    cout<<sol.maxSubArrayDP(b)<<endl;
    cout<<sol.maxSubArrayDP(c)<<endl;
    return 0;
}