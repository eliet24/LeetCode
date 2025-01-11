from collections import Counter


class Solution(object):
    def lengthOfLongestSubstring(self, s: str) -> int:
        def check(start, end):
            chars = set()
            for i in range(start, end + 1):
                c = s[i]
                if c in chars:
                    return False
                chars.add(c)
            return True

        maxlen = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if check(i, j):
                    maxlen = max(maxlen, j - i + 1)
        return maxlen


    def longestSubStringByWindow(self, s):
        chars = Counter()
        left = right = 0
        maxlen = 0
        while right < len(s):
            r = s[right]
            chars[r] += 1
            while chars[r] > 1:
                l = s[left]
                chars[l] -=1
                left += 1

            maxlen = max(maxlen, right - left + 1)
            right += 1
        return maxlen



s = Solution()
print (s.lengthOfLongestSubstring('aabbabcdeeabcdef'))
print (s.longestSubStringByWindow('aabbabcdeeabcdef'))