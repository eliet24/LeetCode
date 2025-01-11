#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <stack>
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
    bool isValidBST(TreeNode *root)
    {
        vector<int> vals;
        inorderPush(root, vals);
        for(int i = 0; i < vals.size() - 1; i++)
        {
            if(vals[i] >= vals[i+1])
                return false;
        }
        return true;
    }
    void inorderPush(TreeNode *node, vector<int> &vals)
    {
        if (node == NULL)
            return;
        inorderPush(node->left, vals);
        vals.push_back(node->val);
        inorderPush(node->right, vals);
    }
};