#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int size = board.size();
        for (int i = 0; i < size; i++)
        {
            if (i % 3 == 0 && !checkSquare(board, i))
                return false;
            if (!checkColumn(board, i) || !checkRow(board, i))
                return false;
        }
        return true;
    }

    bool checkColumn(vector<vector<char>> &board, int column)
    {
        int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
        for(int i = 0; i< board.size(); i++)
        {
            sum = sum - board[i][column];
        }
        if (sum == 0)
            return true;
        else 
            return false;
    }

    bool checkRow(vector<vector<char>> &board, int row)
    {
        int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
        for(int i = 0; i< board.size(); i++)
        {
            sum = sum - board[row][i];
        }
        if (sum == 0)
            return true;
        else 
            return false;
    }

    bool checkSquare(vector<vector<char>> &board, int corner)
    {
        int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
        for (int i = corner; i< board.size() / 3; i++)
        {
            for (int j = corner; j< board.size() / 3; j++)
            sum = sum - board[i][j];
        }
        if (sum == 0)
            return true;
        else 
            return false;
    }
};