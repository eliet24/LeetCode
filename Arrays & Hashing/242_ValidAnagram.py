class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        countdict_s, countdict_t = {}, {}

        for i in range(len(s)):
            countdict_s[s[i]] = countdict_s.get(s[i], 0) + 1
            countdict_t[t[i]] = countdict_t.get(t[i], 0) + 1

        return countdict_s == countdict_t


sol = Solution()
print(sol.isAnagram("anagram", "nagaram"))

