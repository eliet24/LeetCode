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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSym(root->left, root->right);
    }
    bool checkSym(TreeNode *nleft, TreeNode *nright)
    {
        if(nleft == NULL && nright == NULL)
            return true;
        if((nleft != NULL && nright == NULL)||(nleft == NULL && nright != NULL)) 
            return false;
        else if(nleft->val != nright->val)
            return false;
        return checkSym(nleft->left, nright->right) && checkSym(nleft->right, nright->left);
    }
};