class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split(" ")
        i = len(words) - 1
        while i >= 0:
            if words[i] != '':
                return len(words[i])
            i -= 1

    def lengthOfLastWord2(self, s: str) -> int:
        length = 0
        for c in s[::-1]:
            if c == " ":
                if length >= 1:
                    return length
            else:
                length += 1
        return length


sol = Solution()
print(sol.lengthOfLastWord("   fly me   to   the moon  "))

