#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        return checkJumps(nums, 0, nums.size() - 1);
    }

    bool checkJumps(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return true;
        int largest_jump = nums[start];
        for (int i = 1; i <= largest_jump; i++)
        {
            if (start + i <= end)
                return checkJumps(nums, start + i, end);
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums2 = {1, 1};
    vector<int> nums3 = {3,2,1,0,4};
    vector<int> nums4 = {3,2,1,4,0};
    vector<int> nums5 = {0,2,1,1,4};
    Solution sol;
    cout << sol.canJump(nums) << endl;
    cout << sol.canJump(nums2) << endl;
    cout << sol.canJump(nums3) << endl;
    cout << sol.canJump(nums4) << endl;
    cout << sol.canJump(nums5) << endl;
    return 0;
}