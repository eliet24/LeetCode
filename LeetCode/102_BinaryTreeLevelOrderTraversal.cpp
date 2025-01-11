#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> result;
        vector<int> level;
        int n;
        queue<TreeNode *> q;
        TreeNode *p;
        q.push(root);
        while (!q.empty())
        {
            n = q.size();
            level.clear();
            while (n--)
            {
                p = q.front();
                q.pop();
                level.push_back(p->val);
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }

    vector<vector<int>> levelOrderRecu(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode *root, vector<vector<int>> &ans, int i = 0)
    {
        if (!root)
            return;
        if (i >= ans.size())
            ans.push_back({});
        ans[i].push_back(root->val);
        dfs(root->left, ans, i + 1);
        dfs(root->right, ans, i + 1);
    }
};

int main()
{
    TreeNode father(3);
    TreeNode left1(9);
    TreeNode right1(20);
    TreeNode left2(15);
    TreeNode right2(7);
    TreeNode *root = &father;
    root->left = &left1;
    root->right = &right1;
    root->right->left = &left2;
    root->right->right = &right2;
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    vector<vector<int>> result2 = sol.levelOrderRecu(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j % 2 == 0 && (i != 0 || j != 0))
                cout << ",";
        }
        cout << "],";
    }
    cout << endl;
    for (int i = 0; i < result2.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result2[i].size(); j++)
        {
            cout << result2[i][j];
            if (j % 2 == 0 && (i != 0 || j != 0))
                cout << ",";
        }
        cout << "],";
    }
    return 0;
}