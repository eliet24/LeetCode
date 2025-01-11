# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        tail = ListNode(0) 
        tail.next = head
        curr = tail

        while curr.next and curr.next.next:
            first = curr.next
            second = curr.next.next
            curr.next = second
            first.next = second.next
            second.next = first
            curr = curr.next.next
        return tail.next


        return head

sol = Solution()
head = tail = ListNode(1)

for i in range (2,6):
    tail.next = ListNode(i)
    tail = tail.next

sol.swapPairs(head)

