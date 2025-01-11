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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return nullptr;
        if (n == 1)
        {
            TreeNode *root = new TreeNode(nums[0]);
            return root;
        }
        return buildBST(nums, 0, n - 1);
    }

    TreeNode* buildBST(vector<int> &nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }
};