class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [[] for row in range(numRows)]
        index = 0

        for c in s:
            rows[index].append(c)

            if index == 0:
                step = 1
            elif index == numRows - 1:
                step = -1

            index = index + step

        for i in range (numRows):
            rows[i] = ''.join(rows[i])

        return ''.join(rows)





