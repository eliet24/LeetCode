#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
    ListNode(): val(0), next(NULL){}
} ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=0, y=0, carry = 0, sum=0;
        ListNode *temp_l1= l1;
        ListNode *temp_l2 = l2;
        ListNode *head;   
        ListNode **curr = &head;
        while(temp_l1 != NULL || temp_l2 != NULL)
        {
            x = getValMoveNext(temp_l1);
            y = getValMoveNext(temp_l2);
            sum = carry + x + y;
            ListNode *node = new ListNode(sum%10);
            *curr = node;
            curr = &node->next;

            carry = sum / 10;
        }
        if(carry > 0){
            ListNode *last_node = new ListNode(carry%10);
            *curr = last_node;
        }
        return head;
    }

     int getValMoveNext(ListNode* &list){
        int x = 0;
        if (list != NULL){
            x = list->val;
            list = list->next;
        }
        return x;
    }

    void printResult(ListNode *head){
        ListNode * temp_head = head;
        while(temp_head != NULL){
            printf("%d", temp_head->val);
            temp_head = temp_head->next;
        }
    }
};



int main(){
    Solution sol;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode (3);
    l1->next->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode (3);
    ListNode *result = sol.addTwoNumbers(l1, l2);
    sol.printResult(result);

    return 0;
}