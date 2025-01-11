#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int size = board.size();
        for (int i = 0; i < size; i++)
        {
            if (!checkColumn(board, i) || !checkRow(board, i))
                return false;
        }
        for (int i = 0; i < size - (size / 3); i = i + (size / 3))
        {
            for (int j = 0; j < size - (size / 3); j = j + (size / 3))
            {
                if (!checkSquare(board, i, j))
                    return false;
            }
        }
        return true;
    }

    bool checkColumn(vector<vector<char>> &board, int column)
    {
        unordered_map<char, char> m;
        for (int i = 0; i < board.size(); i++)
        {
            if (m.find(board[i][column]) != m.end())
            {
                if (board[i][column] != '.')
                    m.insert({board[i][column], board[i][column]});
            }
            else
                return false;
        }
        return true;
    }

    bool checkRow(vector<vector<char>> &board, int row)
    {
        unordered_map<char, char> m;
        for (int i = 0; i < board.size(); i++)
        {
            if (m.find(board[row][i]) != m.end())
            {
                if (board[row][i] != '.')
                    m.insert({board[row][i], board[row][i]});
            }
            else
                return false;
        }
        return true;
    }
    bool checkSquare(vector<vector<char>> &board, int row, int col)
    {
        unordered_map<char, char> m;
        for (int i = row; i < row + 3; i++)
        {
            for (int j = col; j < col + 3; j++)
            {
                if (m.find(board[row][col]) != m.end())
                {
                    if (board[row][col] != '.')
                        m.insert({board[row][col], board[row][col]});
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}