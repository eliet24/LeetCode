from typing import List


class Solution:
    def longestCommonPrefixBruteForce(self, strs: List[str]) -> str:
        prefix = ""
        for index in range(0, len(strs[0])):
            c = strs[0][index]
            for word in strs:
                if word[index] != c:
                    return prefix
            prefix = prefix + c
 
        return prefix

    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        strs = sorted(strs)
        first = strs[0]
        last = strs[-1]
        for i in range(min(len(first), len(last))):
            if first[i] != last[i]:
                return prefix
            prefix += first[i]

        return prefix



sol = Solution()
strs = ["flower", "flow", "flight"]
print(sol.longestCommonPrefix(strs))
