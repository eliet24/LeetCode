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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> index_map;
        int preorder_index = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            index_map[inorder[i]] = i;
        }
        return buildSubTree(preorder, preorder_index, index_map, 0, preorder.size() - 1);       
    }

    TreeNode * buildSubTree(vector<int> &preorder, int preorder_index, unordered_map<int, int> &index_map, int left, int right)
    {
        if(left > right)
            return nullptr;
        int val = preorder[preorder_index++];
        TreeNode *root = new TreeNode(val);
        int inorder_index = index_map[val];
        root->left = buildSubTree(preorder, preorder_index, index_map, left, inorder_index - 1);
        root->right = buildSubTree(preorder, preorder_index, index_map, inorder_index + 1, right);
        return root;
    }
};