from typing import List


class Solution:

    def find_three_max(self, numbers: List[int], index=0, mul_result=1, num_count=0):
        if num_count == 3:
            return mul_result

        if index == len(numbers):
            return float('-inf')

        three_nums_mul = self.find_three_max(numbers, index+1, mul_result * numbers[index], num_count + 1)

        next_nums_mul = self.find_three_max(numbers, index+1, mul_result, num_count)

        return max(three_nums_mul, next_nums_mul)




# Example usage
sol = Solution()
my_array = [2, -3, 1, 4, -2]
result = sol.find_three_max(my_array)
print("Best Multiplication:", result)

