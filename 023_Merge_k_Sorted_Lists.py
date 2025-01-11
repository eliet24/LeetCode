# Definition for singly-linked list.
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0 or lists in None:
            return None

        def merge2lists(l1: [ListNode], l2: [ListNode]) -> [ListNode]:
            head = ListNode()
            tail = head

            while l1 and l2:
                if l1.val > l2.val:
                    tail.next = l2
                    l2 = l2.next
                else:
                    tail.next = l1
                    l1 = l1.next
            tail = tail.next

            while l1:
                tail.next = l1
                l1 = l1.next
                tail = tail.next

            while l2:
                tail.next = l2
                l2 = l2.next
                tail = tail.next

            return head.next

        while len(lists) > 1:
            result = []
            for i in range(0, len(lists), 2):
                left_list = lists[i]
                if i+1 < len(lists):
                    right_list = list[i+1]
                else:
                    right_list = None
                result.append(merge2lists(left_list, right_list))
            lists = result
        return lists[0]

