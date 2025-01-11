#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool flag_first_col = false, flag_first_row = false;
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                flag_first_col = true;
        }
        for (int j = 0; j < cols; j++)
        {
            if (matrix[0][j] == 0)
                flag_first_row = true;
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (flag_first_col == true)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
        if (flag_first_row == true)
        {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
        }
    }

    void setZeroes2(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_set<int> set_rows;
        unordered_set<int> set_cols;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    set_rows.insert(i);
                    set_cols.insert(j);
                }
            }
        }
        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if((set_rows.find(i) != set_rows.end()) || (set_cols.find(j) != set_cols.end()))
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution sol;
    sol.setZeroes2(vec);
    vector<vector<int>> vec2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    sol.setZeroes2(vec2);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
    }
    cout << endl;
    for (int i = 0; i < vec2.size(); i++)
    {
        for (int j = 0; j < vec2[i].size(); j++)
            cout << vec2[i][j] << " ";
    }
    vector<vector<int>> vec4 = {{1, 0}};
    sol.setZeroes2(vec4);
    cout << endl;
    for (int i = 0; i < vec4.size(); i++)
    {
        for (int j = 0; j < vec4[i].size(); j++)
            cout << vec4[i][j] << " ";
    }
    return 0;
}