#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int dir = 0; // left to right--> 0, top to bottom--> 1, right to left--> 2, bottom to top--> 3
        vector<int> spiral;
        while (top <= bottom && left <= right)
        {
            // left to right
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    spiral.push_back(matrix[top][i]);
                }
                top++;
            }
            // top to bottom
            else if (dir == 1)
            {
                for (int i = top; i < rows; i++)
                {
                    spiral.push_back(matrix[i][right]);
                }
                right--;
            }
            // right to left
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // bottom to top
            else if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
            // cout << spiral.back() << endl;
        }
        return spiral;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution sol;
    cout << sol.spiralOrder(matrix) << endl;
    cout << sol.spiralOrder(matrix2) << endl;
    return 0;
}