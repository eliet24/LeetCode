from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        first_pointer = 1
        second_pointer = n
        while second_pointer != len(nums)-1:
            temp = nums[second_pointer]
            for i in range(second_pointer, first_pointer, -1):
                nums[i] = nums[i-1]
            nums[first_pointer] = temp
            second_pointer += 1
            first_pointer += 2

        print(nums)
        return nums


sol = Solution()
sol.shuffle([2,5,1,3,4,7], 3)
sol.shuffle([1,1,2,2], 2)
sol.shuffle([1,2,3,4,4,3,2,1], 4)