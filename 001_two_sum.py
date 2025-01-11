from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # :type nums: List[int]
        # :type target: int
        #     :rtype: List[int]
        #     """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i]+nums[j] == target:
                    return [i, j]

    def two_sum_hushTable(self, nums, target):
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]]

    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        complements_map = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in complements_map:
                return [complements_map[diff], i]
            complements_map[n] = i


s = Solution()
# print(s.two_sum([3, 2, 4], 6))
# print(s.two_sum([2, 7, 11, 15], 9))

print(s.two_sum_hushTable([3, 2, 4], 6))
print(s.two_sum_hushTable([2, 7, 11, 15], 9))
print(s.two_sum_hushTable([2, 7, 11, 15], 10))
