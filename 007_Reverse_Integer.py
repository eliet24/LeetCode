class Solution:
    def reverseInteger(self, x):
      num = x if x > 0 else -x
      reversed = 0
      while num != 0:
          reversed = reversed * 10
          reversed = reversed + (num % 10)
          num = num // 10
      reversed = reversed if x > 0 else -reversed
      if reversed > pow(2, 31)-1 or reversed < -pow(2, 31):
          return 0
      return reversed

    def reverse(self, x: int) -> int:
        if x > 0:
            res = int(str(x)[::-1])
        else:
            res = int("-" + str(abs(x))[::-1])

        if res >= -2 ^ 31 and x <= 2 ^ 31 - 1:
            return res
        else:
            return 0


s = Solution()
print(s.reverseInteger(123))
print(s.reverseInteger(-123))
print(s.reverseInteger(-120))
print(s.reverseInteger(31^31))
