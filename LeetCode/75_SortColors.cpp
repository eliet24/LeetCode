#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

template <typename S>
ostream &operator<<(ostream &os, const vector<S> &vector)
{
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (mid <= high)
        {
            switch (nums[mid])
            {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {0, 1, 2};
    Solution sol;
    sol.sortColors(nums1);
    sol.sortColors(nums2);
    cout << nums1 << endl;
    cout << nums2 << endl;
    return 0;
}