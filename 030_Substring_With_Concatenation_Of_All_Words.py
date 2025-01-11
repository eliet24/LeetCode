from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []

        word_length = len(words[0])
        total_length = len(words) * word_length
        word_count = {}

        # Count occurrences of each word in the words list
        for word in words:
            if word in word_count:
                word_count[word] += 1
            else:
                word_count[word] = 1

        indexes = []
        for i in range(len(s) - total_length + 1):
            substring = s[i:i + total_length]
            found_words = {}

            for j in range(0, total_length, word_length):
                word = substring[j: j + word_length]
                if word in found_words:
                    found_words[word] += 1
                else:
                    found_words[word] = 1

            # compare word_count and found_words
            if found_words == word_count:
                indexes.append(i)

        return indexes


sol = Solution()
s = "barfoothefoobarman"
words = ["foo","bar"]
print(sol.findSubstring(s, words))





