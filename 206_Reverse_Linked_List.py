# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tail = None
        if head is None:
            return None
        while head:
            temp = head.next
            head.next = tail
            tail = head
            head = temp

        return tail

    def print_linked_list(self, head):
        current = head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")


sol = Solution()
a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)
e = ListNode(5)

head = a
a.next = b
b.next = c
c.next = d
d.next = e
rev_head = sol.reverseList(head)
sol.print_linked_list(rev_head)

