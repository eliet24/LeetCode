class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) == len(needle) == 1 and haystack[0] == needle[0]:
            return 0
        if len(haystack) < len(needle):
            return -1
        for i in range(len(haystack)):
            if haystack[i] == needle[0]:
                j = 0
                while j < len(needle):
                    if i + j >= len(haystack) or haystack[i + j] != needle[j]:
                        break
                    j += 1
                if j == len(needle):
                    return i
        return -1

sol = Solution()
print(sol.strStr("abc", "c"))