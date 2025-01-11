#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename S>
ostream &operator<<(ostream &os,
                    const vector<S> &vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do
        {
            ans.push_back(nums);
            cout << nums << endl;
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> numbers{1, 2, 3};
    sol.permute(numbers);
    return 0;
}