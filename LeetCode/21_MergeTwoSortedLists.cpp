#include <stdio.h>
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL) {}
};

class Solution
{
public:
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *new_head = NULL;
        ListNode *curr = NULL;
        ListNode *tmp = NULL;
        while (l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                tmp = l1;
                l1 = l1->next;
            }
            else
            {
                tmp = l2;
                l2 = l2->next;
            }
            if(!curr)
            {
                new_head = tmp;
                curr = tmp;
            }
            else
            {
                curr->next = tmp;
                curr = curr->next;
            }
        }
        //checking the tail of the longer list and add it.
        if(l1)          
            tmp = l1;
        else if(l2)
            tmp = l2;
        if(tmp)
        {
            curr->next = tmp;
        }
        return new_head;
    }

    void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    Solution sol;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *head = sol.mergeTwoLists(l1, l2);
    sol.printList(head);
    return 0;
}