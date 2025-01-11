# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        count = 0
        temp = head
        while temp:
            temp = temp.next
            count += 1

        n = count // k
        a = dummy = ListNode()
        dummy.next = head
        while n:
            b = a.next
            c = b.next
            for i in range(1, k):
                b.next = c.next
                c.next = a.next
                a.next = c
                c = b.next
            a = b
            n -= 1
        return dummy.next

sol =Solution()
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
k = 2
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

print(sol.reverseKGroup(node1, k))

