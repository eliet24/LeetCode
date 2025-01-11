class Solution:
    def longestPalindrome(self, s: str) -> str:   #brute force algoritham Time Complexity: O(n3) Space Complexity: O(1)
        if len(s) <= 1:
            return s
        max_len = 1
        max_str = s[0]
        for i in range(len(s) - 1):
            for j in range(i+1, len(s)):
                if j-i+1 > max_len and s[i:j+1] == s[i:j+1][::-1]:
                    max_len = j-i+1
                    max_str = s[i:j+1]
        return max_str




    def longestPalindromeCenterExpand(self,s):    #center expanded palindrome algo Time Complexity: O(n2) Space Complexity: O(1)
        def expandFromCenter(s, idx1, idx2):
            while idx1 >= 0 and idx2 < len(s) and s[idx1] == s[idx2]:
                idx1 -= 1
                idx2 += 1
            return idx2 - idx1 - 1

        if s == "": return s
        max_len = 0
        start, end = 0, 0
        for i in range(len(s)):
            len1 = expandFromCenter(s, i, i)
            len2 = expandFromCenter(s, i, i+1)
            l = max(len1, len2)
            if l > end - start:
                start = i - (l - 1) // 2
                end = i + l // 2
        return s[start:end+1]


s = Solution()
print(s.longestPalindrome('dcaaabaaadc'))
print(s.longestPalindrome('abcdefghg'))
print(s.longestPalindromeCenterExpand('dcaaabbbaaadc'))





