#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (!root)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        while(size(q))
        {
            Node* right_node = nullptr;
            for (int i = size(q); i; i--)
            {
                auto curr = q.front(); 
                q.pop();
                curr->next = right_node;
                right_node = curr;
                if(curr->right)
                {
                    q.push(curr->right); 
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};