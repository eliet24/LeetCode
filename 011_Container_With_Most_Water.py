from typing import List


class Solution:
    def maxAreaBruteForce(self, height: List[int]) -> int:
        max_sum = 0
        for left in range(0, len(height)):
            for right in range(left + 1, len(height)):
                temp_sum = min(height[left], height[right]) * (right - left)
                if temp_sum > max_sum:
                    max_sum = temp_sum

        return max_sum

    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0
        while left < right:
            current_area = (right-left) * min(height[left], height[right])
            max_area = max(max_area, current_area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area





sol = Solution()
