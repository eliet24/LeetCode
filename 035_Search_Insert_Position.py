from typing import List


class Solution:

    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid

            elif nums[l] < target < nums[r] and r - l == 1:
                return r

            elif target < nums[mid]:
                r = mid

            else:
                l = mid + 1

        if target <= nums[l]:
            return l
        else:
            return l + 1


    def searchInsertRecu(self, nums: List[int], target: int) -> int:
        def binary_search(nums: List[int], target: int, left: int, right: int) -> int:
            if left > right:
                return left

            mid = (left + right)//2

            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                return binary_search(nums, target, left, mid-1)
            else:
                return binary_search(nums, target, mid+1, right)

        return binary_search(nums, target, 0, len(nums) - 1)



sol = Solution()
nums = [1,3,5,6]
target = 5
nums2 = [1,3,5,6]
target2 = 2
nums3 = [1,3,5,6]
target3 = 7
nums4 =[1,3,5,6]
target4 = 0
nums5 = [1]
target5 = 1
nums6 = [1,3]
target6 = 2
nums7 = [1,3, 5]
target7 = 4
nums8 = [1,3]
target8 = 3
print(sol.searchInsert(nums, target))
print(sol.searchInsert(nums2, target2))
print(sol.searchInsert(nums3, target3))
print(sol.searchInsert(nums4, target4))
print(sol.searchInsert(nums5, target5))
print(sol.searchInsert(nums6, target6))
print(sol.searchInsert(nums7, target7))
print(sol.searchInsert(nums8, target8))
print("--------------------------------------")
print(sol.searchInsertRecu(nums, target))
print(sol.searchInsertRecu(nums2, target2))
print(sol.searchInsertRecu(nums3, target3))
print(sol.searchInsertRecu(nums4, target4))
print(sol.searchInsertRecu(nums5, target5))
print(sol.searchInsertRecu(nums6, target6))
print(sol.searchInsertRecu(nums7, target7))
print(sol.searchInsertRecu(nums8, target8))