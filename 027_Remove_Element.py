from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        head = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            tail = i - 1
            if nums[head] == val:
                nums.pop()
                head -= 1
            elif nums[tail] == val and nums[head] != val:
                nums[tail] = nums.pop()
                head -= 1

        return len(nums)

sol = Solution()
print(sol.removeElement([2,1,2,2,3,0,2], 2))