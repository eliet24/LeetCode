#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        vector<int> inter;
        int size = intervals.size();
        int start;
        int next_start;
        int end;
        sort(intervals.begin(), intervals.end());
        if (size <= 1)
            return intervals;
        for (int i = 0; i <= intervals.size() - 2; i++)
        {
            start = intervals[i][0];
            end = intervals[i][1];
            next_start = intervals[i + 1][0];
            while (next_start <= end)
            {
                i++;
                if (intervals[i][1] > end)
                    end = intervals[i][1];
                if (i + 1 > size - 1)
                    break;
                next_start = intervals[i + 1][0];
            }
            inter.push_back(start);
            inter.push_back(end);
            result.push_back(inter);
            inter.clear();
        }
        if (result[result.size() - 1][1] != intervals[size - 1][1] && end <= intervals[size - 1][1])
        {
            start = intervals[size - 1][0];
            end = intervals[size - 1][1];
            inter.push_back(start);
            inter.push_back(end);
            result.push_back(inter);
            inter.clear();
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> intervals3 = {{1, 4}, {4, 5}, {4, 9}};
    vector<vector<int>> intervals4 = {{1, 4}, {2, 3}};
    Solution sol;
    vector<vector<int>> vec = sol.merge(intervals);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout << endl;
    vec = sol.merge(intervals2);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout << endl;
    vec = sol.merge(intervals3);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout << endl;
    vec = sol.merge(intervals4);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout << endl;
}