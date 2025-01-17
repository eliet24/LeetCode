class Solution:
    def romanToInt(self, s: str) -> int:
        num_map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000,
                   "IV": 4, "IX": 9, "XL": 40, "XC": 90, "CD": 400, "CM": 900}

        num = 0
        for i in range(len(s)):
            if i < len(s) - 1 and num_map[s[i]] < num_map[s[i+1]]:
                num -= num_map[s[i]]
            else:
                num += num_map[s[i]]

        return num

sol = Solution()
s = "MCMXCIV"
print(sol.romanToInt(s))