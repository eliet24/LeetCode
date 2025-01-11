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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
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
        cout << sol.maxDepth(root);
    }