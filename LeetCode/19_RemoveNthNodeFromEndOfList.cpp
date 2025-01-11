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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (n <= 0)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (n)
        {
            fast = fast->next;
            n--;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // slow->next = NULL;
        // free(slow->next);
        slow->next = slow->next->next;
        return head;
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
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    sol.printList(n1);
    sol.removeNthFromEnd(n1, 2);
    sol.printList(n1);
    return 0;
}