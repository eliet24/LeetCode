class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        mid = len(nums) // 2
        left = self.sortArray(nums[:mid])
        right = self.sortArray(nums[mid:])
        return self.merge(left, right)
    def quickSort(self, nums: List[int], low: int, high: int):
        if low < high:
            pivot = self.partition(nums, low, high)
            self.quickSort(nums, low, pivot - 1)
            self.quickSort(nums, pivot + 1, high)

    def partition(self, nums: List[int], low:int, high:int) -> int:
        pivot_index = random.randint(low, high)
        nums[pivot_index], nums[high] = nums[high], nums[pivot_index]
        pivot = nums[high]
        i = low - 1
        for j in range (low, high):
            if nums[j] < pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i+1], nums[high] = nums[high], nums[i+1]
        return i + 1

    def merge(self, left: List[int], right: List[int]) -> List[int]:
        merged = []
        i = j = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                j += 1

        # Add remaining elements of left
        while i < len(left):
            merged.append(left[i])
            i += 1
        # Add remaining elements of right
        while j < len(right):
            merged.append(right[j])
            j += 1

        return merged
