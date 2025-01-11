from typing import List


class Solution:
    def removeDuplicatesUsingSet(self, nums: List[int]) -> int:
        if not nums or len(nums) == 1:
            return len(nums)

        unique_nums = set()
        count = 0
        for num in nums:
            if num not in unique_nums:
                unique_nums.add(num)
                count += 1
        nums.clear()
        nums = unique_nums
        return count

    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums or len(nums) == 1:
            return len(nums)
        j = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[j] = nums[i]
                j += 1

        nums = nums[:j]
        print(nums)
        return j




sol = Solution()
nums = [1,2,3,3,4,5,5,6,6]
print(sol.removeDuplicates(nums))