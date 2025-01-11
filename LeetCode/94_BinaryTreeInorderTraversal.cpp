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

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vector)
{
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    void traverse(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
            return;
        traverse(root->left, result);
        result.push_back(root->val);
        traverse(root->right, result);
    }

    vector<int> inorderTraversal_it(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        while (true)
        {
            if (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                    break;
                root = st.top();
                st.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};

int main()
{
    TreeNode left(3);

    TreeNode right(2, &left, nullptr);
    TreeNode root(1, nullptr, &right);
    Solution sol;
    cout << sol.inorderTraversal(&root) << endl;
    cout << sol.inorderTraversal_it(&root) << endl;
    return 0;
}