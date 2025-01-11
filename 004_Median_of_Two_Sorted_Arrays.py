from typing import List


class Solution:
    def findMedianSortedArraysGPT(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        len1, len2 = len(nums1), len(nums2)
        low, high = 0, len1

        while low <= high:
            partition1 = (low + high) // 2
            partition2 = (len1 + len2 + 1) // 2 - partition1


    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_list = sorted(nums1 + nums2)
        if len(merged_list) % 2 == 0:
            left, right = merged_list[len(merged_list) // 2 - 1], merged_list[len(merged_list) // 2]
            return (left + right) / 2
        else:
            return merged_list[len(merged_list) // 2]



s = Solution()
print("first check: num1 = [1,2,5,6], num2 = [3,4]")
nums1 = [1,2]
nums2 = [3,4]
n1 = [1,2,3,4,5,6]
n2 = [1,2,5,6,7]
print ("the median is" + " " + str(s.findMedianSortedArrays(nums1, nums2)))
print("second check: n1 = [1,2,3,4,5,6], n2 = [1,2,5,6,7]")
print ("the median is" + " "+ str(s.findMedianSortedArrays(n1, n2)))

