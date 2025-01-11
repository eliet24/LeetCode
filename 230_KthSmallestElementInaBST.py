# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    def inorderTraversalIterative(self, root: Optional[TreeNode]) -> List[int]:
        traversal = []
        stack = []
        current = root

        while current is not None or stack:
            # Reach the leftmost node of the current node
            while current is not None:
                stack.append(current)
                current = current.left

            # Current is None at this point, pop from stack
            current = stack.pop()
            traversal.append(current.val)

            # We have visited the node and its left subtree. Now, it's right subtree's turn
            current = current.right

        return traversal

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        traversal = self.inorderTraversalIterative(root)
        return traversal[k-1]
