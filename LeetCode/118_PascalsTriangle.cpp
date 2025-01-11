#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++)
        {
            result[i].resize(i+1, 1);
            for(int j = 1; j < i; j++)
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};