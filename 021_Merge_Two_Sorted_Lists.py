# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head1, head2 = list1, list2
        if head1 is None or head2 is None:
            return head1 or head2

        if head1.val <= head2.val:
            merged_list = ListNode(head1.val)
            head1 = head1.next
        else:
            merged_list = ListNode(head2.val)
            head2 = head2.next

        merged_head = merged_list
        while head1 and head2:
            if head1.val <= head2.val:
                merged_head.next = ListNode(head1.val)
                head1 = head1.next
            else:
                merged_head.next = ListNode(head2.val)
                head2 = head2.next

            merged_head = merged_head.next

        merged_head.next = head1 or head2

        return merged_list

