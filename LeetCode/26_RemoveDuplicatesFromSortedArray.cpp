#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int fast = 1;
        int slow = 0;
        int dups = 0;
        while (fast != nums.size())
        {
            if (nums[slow] != nums[fast])
            {
                nums[slow + 1] = nums[fast];
                slow++;
                fast++;
            }
            else
            {
                fast++;
                dups++;
            }
        }
        int new_size = nums.size() - dups;
        auto new_end = nums.begin() + new_size;
        nums.erase(new_end, nums.end());
        return nums.size();
    }
};

template <typename S>
ostream &operator<<(ostream &os, const vector<S> &vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

int main()
{
    vector<int> a = {0, 0, 0, 1, 1, 1, 2, 3, 3, 4, 5, 5};
    Solution sol;
    int unique_nums = sol.removeDuplicates(a);
    cout << "number of unique numbers is: " << unique_nums << endl << a << endl;
    return 0;
}