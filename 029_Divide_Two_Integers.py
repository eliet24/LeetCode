class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        temp = divisor
        if dividend == 0:
            return 0

        if dividend == -2**31 and divisor == -1:
            return 2**31-1

        #  get the sign
        sign = 1
        if dividend < 0:
            dividend = -dividend
            sign = -sign
        if divisor < 0:
            divisor = -divisor
            sign = -sign
        if sign > 0 and dividend < divisor:
            return 0

        multiple = 1
        temp = divisor
        while temp < dividend - divisor:
            temp += divisor
            multiple += 1

        if sign > 0:
            return multiple
        else:
            return -multiple


sol = Solution()
print(sol.divide(-2147483648, -1))