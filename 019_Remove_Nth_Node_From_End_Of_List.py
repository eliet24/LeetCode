# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tail = head
        front = tail
        prev = None
        for i in range(n-1):
            front = front.next

        while front.next is not None:
            prev = tail
            tail = tail.next
            front = front.next

        if prev is None:
            return tail.next
        else:
            prev.next = tail.next
            tail.next = None

        return head





