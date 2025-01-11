#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res;
        vector<int> v;
        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i])
            {
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(rbegin(v), rend(v));
        for (int i = 0; i < v.size(); i++)
        {
            res = new ListNode(v[i], res);
        }
        return res;
    }

    ListNode *mergeKListsRecu(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return mergeKListsFunc(lists, 0, lists.size() - 1);
    }

    ListNode *mergeKListsFunc(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        if (start + 1 == end)
            return merge(lists[start], lists[end]);
        int mid = start + (end - start) / 2;
        ListNode *left = mergeKListsFunc(lists, start, mid);
        ListNode *right = mergeKListsFunc(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode();
        ListNode *curr = temp;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return temp;
    }
};