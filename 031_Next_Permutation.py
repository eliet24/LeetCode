from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # find the first decrising elemnt
        i = len(nums) - 2
        while i >=0 and nums[i] >= nums[i+1]:
            i -= 1

        if i >= 0:
            # find the smallest element to the right of i that is greater than nums[i]
            j = len(nums) - 1
            while j > i and nums[j] <=nums[i]:
                j -= 1

            nums[i], nums[j] = nums[j], nums[i]

        # reverse the sublist to the right of i
        nums[i+1:] = reversed(nums[i+1:])


sol = Solution()
# print(sol.nextPermutation([1,2,3]))
sol.nextPermutation([3,2,1])
