class Solution:
    def climbStairsRecu(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            return self.climbStairs(n-1) + self.climbStairs(n-2)

    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        elif n == 2:
            return 2

        first, second = 1, 2

        # Iterate from 3 to n and update the ways to reach the ith step
        for i in range(3, n + 1):
            third = first + second
            first, second = second, third

        return second