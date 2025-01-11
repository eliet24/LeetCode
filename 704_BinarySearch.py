from typing import Optional, List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) <= 1:
            if nums[0] == target:
                return 0
            else:
                return -1

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if target < nums[mid]:
                right = mid - 1
            elif target > nums[mid]:
                left = mid + 1
            else:
                return mid

        return -1


sol = Solution()
print(sol.search([2,5], 5))