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
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (recuSearch(board, 0, i, j, word))
                        return true;
                }
            }
        }
        return false;
    }

    bool recuSearch(vector<vector<char>> board, int pos, int row, int col, string &word)
    {
        if (row < 0 || col < 0 || row > board.size() - 1 || col > board[0].size() - 1)
            return false;
        else if (board[row][col] != word[pos])
            return false;
        else if (pos == word.length() - 1)
            return true;
        char ch = board[row][col];
        board[row][col] = '-';
        if (recuSearch(board, pos + 1, row + 1, col, word))
            return true;
        if (recuSearch(board, pos + 1, row - 1, col, word))
            return true;
        if (recuSearch(board, pos + 1, row, col + 1, word))
            return true;
        if (recuSearch(board, pos + 1, row, col - 1, word))
            return true;
        board[row][col] = ch;
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << sol.exist(board, "ABCCED") << endl;
    cout << sol.exist(board, "SEE") << endl;
    cout << sol.exist(board, "ABCB") << endl;

    return 0;
}