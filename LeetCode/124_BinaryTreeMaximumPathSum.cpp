#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = root->val;
        solve(root, ans);
        return ans;
    }

    int solve(TreeNode *node, int &ans)
    {
        if (node == NULL)
            return 0;
        int left = solve(node->left, ans);
        int right = solve(node->right, ans);
        int path = node->val;
        path = max(path, path + left);
        path = max(path, path + right);
        ans = max(ans, path);
        return max(node->val, node->val + max(left, right));
    }
};