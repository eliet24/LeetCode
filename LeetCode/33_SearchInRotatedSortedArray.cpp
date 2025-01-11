#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;
        int mid;
        while (i <= j)
        {
            mid = (i + j) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[i] <= nums[mid])
            {
                if (nums[i] <= target && nums[mid] >= target)
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> numbers = {6, 7, 8, 9, 0, 1, 2, 3};
    cout << sol.search(numbers, 9) << endl;
    cout << sol.search(numbers, 1) << endl;
    return 0;
}