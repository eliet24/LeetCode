class Solution:
    def isMatch(self, text, pattern):
        # Base case: if the pattern is empty, return True if the text is also empty
        if not pattern:
            return not text

        # Check the first character of the text and pattern
        first_match = bool(text) and pattern[0] in {text[0], '.'}

        # If the second character in the pattern is '*', handle the case
        if len(pattern) >= 2 and pattern[1] == '*':
            # Two possibilities:
            # 1. Ignore the '*' and the character before it in the pattern (pattern[2:])
            # 2. Keep the first character match and move to the next character in the text (text[1:])
            return (self.isMatch(text, pattern[2:]) or first_match and self.isMatch(text[1:], pattern))
        else:
            # If no '*', simply move to the next characters in both text and pattern
            return first_match and self.isMatch(text[1:], pattern[1:])


    def isMatch2(self, s: str, p: str) -> bool:
        memo = {}
        def backtrack(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            if j == -1:
                result = i == -1
            elif i == -1:
                result = j > 0 and p[j] == '*' and backtrack(i, j - 2)
            elif p[j] == '*':
                result = (backtrack(i, j - 2) or
                          (p[j - 1] == s[i] or p[j - 1] == '.') and backtrack(i - 1, j))
            else:
                result = (p[j] == '.' or s[i] == p[j]) and backtrack(i - 1, j - 1)

            memo[(i, j)] = result
            return result

        return backtrack(len(s) - 1, len(p) - 1)


s = Solution()
print(s.isMatch("aaaaa", "a*"))
print(s.isMatch("aaavbvggddfgdfjkkowaa", ".*"))
print(s.isMatch("cccccac", "c*"))
print(s.isMatch("aaaaabcdd", "a*bcd*"))
print(s.isMatch2("aaaaa", "a*"))
print(s.isMatch2("aaavbvggddfgdfjkkowaa", ".*"))
print(s.isMatch2("cccccac", "c*"))
print(s.isMatch2("aaaaabcdd", "a*bcd*"))