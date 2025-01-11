#include <iostream>
#include <vector>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int start_pos = lowerBound(nums, low, high, target);
        int end_pos = lowerBound(nums, low, high, target + 1) - 1;
        if (start_pos < nums.size() && nums[start_pos] == target)
            return {start_pos, end_pos};
        return {-1, -1};
    }

    int lowerBound(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution sol;
    cout << sol.searchRange(nums, target);
}