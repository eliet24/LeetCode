import collections
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)
        for s in strs:
            sorted_s = ''.join(sorted(s))
            anagrams[sorted_s].append(s)

        return list(anagrams.values())


sol = Solution()
print(sol.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
