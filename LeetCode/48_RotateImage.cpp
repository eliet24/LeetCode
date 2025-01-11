#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int size = matrix[0].size();
        int save_size = size;
        for (int a = 0; a < save_size; a++)
        {
            if (size >= 1)
            {
                rotateFrame(matrix, a, a, size);
                        size = size / 2;
            }
        }
    }

    void rotateFrame(vector<vector<int>> &matrix, int i, int j, int size)
    {
        vector<int> temp;
        for (int k = 0; k < size; k++)
        {
            temp.push_back(matrix[i][k+j]);
        }
        for (int k = 0; k < size; k++)
        {
            matrix[i][k+j] = matrix[size-1-k][j];
        }
        for (int k = 0; k < size; k++)
        {
            matrix[i+k][j] = matrix[size - 1+i][j+k];
        }
        for (int k = 0; k < size; k++)
        {
            matrix[size - 1 +i][k+j] = matrix[size-1-k+i][size - 1+j];
        }
        for (int k = 0; k < size; k++)
        {
            matrix[i+k][size - 1+j] = temp[k];
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix0 = {{1, 2}, {3,4}};
    sol.rotate(matrix0);
    cout << matrix0<< endl;
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix1);
    cout << matrix1<< endl;
    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(matrix2);
    cout << matrix2<< endl;

    return 0;
}