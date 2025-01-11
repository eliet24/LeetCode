#include <iostream>
#include <vector>
using namespace std;

class IslandsGrid
{
    public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &v, int i, int j)
    {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size()|| v[i][j] == '0')
            return;
        v[i][j] = '0';
        dfs(v, i - 1, j);
        dfs(v, i + 1, j);
        dfs(v, i, j - 1);
        dfs(v, i, j + 1);
    }
};

int main()
{
    IslandsGrid islands_map;
    vector<char> row1{'1','1','1','1','0'};
    vector<char> row2{'1','1','0','1','0'};
    vector<char> row3{'1','1','0','0','0'};
    vector<char> row4{'0','0','0','0','0'};
    vector<char> row5{'1','1','0','0','0'};
    vector<char> row6{'1','1','0','0','0'};
    vector<char> row7{'0','0','1','0','0'};
    vector<char> row8{'0','0','0','1','1'};
    vector<vector<char>> islands{row1,row2,row3,row4};
    vector<vector<char>> islands2{row5,row6,row7,row8};
    cout<< "Number of islands for the grid is "<< islands_map.numIslands(islands)<<endl;
    cout<< "Number of islands for the grid is "<< islands_map.numIslands(islands2)<<endl;

    return 0;
}