#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        map<int, int> map;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                map[nums[i]] = nums[i];
                if(nums[i] > max)
                    max = nums[i];
            }
        }
        for (int i = 1; i <= max; i++)
        {
            if (map[i] != i)
            {
                return i;
            }
        }
        return max + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-255, -30, 0, 1, 2, 3, 5};
    cout << sol.firstMissingPositive(v) << endl;
    v = {1, 2, 0};
    cout << sol.firstMissingPositive(v) << endl;
    v = {7,8,9,11,12};
    cout << sol.firstMissingPositive(v) << endl;
}