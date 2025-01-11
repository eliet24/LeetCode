from typing import List


class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        size = len(nums)
        ans = []
        for i in range(0, size):
            ans.append(nums[i])
        for i in range(0, size):
            ans.append(nums[i])
        return ans
