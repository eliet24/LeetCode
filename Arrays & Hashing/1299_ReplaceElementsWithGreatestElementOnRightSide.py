from typing import List


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        max_value = -1
        for i in range(len(arr) - 1, -1, - 1):
            new_max = max(max_value, arr[i])
            arr[i] = max_value
            max_value = new_max
        return arr


sol = Solution()
print(sol.replaceElements([17,18,5,4,6,1]))

