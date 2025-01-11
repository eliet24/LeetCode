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
    int largestRectangleArea(vector<int> &heights)
    {
        int max = -1;
        if (heights.size() == 1)
            return heights[0];
        if (heights.size() == 0)
            return 0;
        if (allEqual(heights))
            return heights[0] * heights.size();
        searchArea(heights, max);
        return max;
    }

    void searchArea(vector<int> heights, int &max)
    {
        int min_index = (min_element(heights.begin(), heights.end()) - heights.begin());
        vector<int> left(min_index);
        int win_size = heights.size();
        vector<int> right(heights.size() - 1 - min_index);
        int min = *min_element(heights.begin(), heights.end());
        if (heights.size() == 1)
        {
            if (min * win_size > max)
                max = min * win_size;
            return;
        }
        if (min * win_size > max)
            max = min * win_size;
        copy(heights.begin(), heights.begin() + min_index, left.begin());
        copy(heights.begin() + min_index + 1, heights.end(), right.begin());
        if (min_index == 0)
        {
            searchArea(right, max);
            return;
        }
        if (min_index == heights.size() - 1)
        {
            searchArea(left, max);
            return;
        }
        else
        {
            searchArea(right, max);
            searchArea(left, max);
        }
    }

    bool allEqual(std::vector<int> const &v)
    {
        return adjacent_find(v.begin(), v.end(), std::not_equal_to<int>()) == v.end();
    }
};

int main()
{
    vector<int> h = {2, 1, 5, 6, 2, 3};
    vector<int> h2 = {2, 4};
    Solution sol;
    cout << sol.largestRectangleArea(h) << endl;
    cout << sol.largestRectangleArea(h2) << endl;
    return 0;
}