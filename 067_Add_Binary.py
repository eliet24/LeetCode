class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        result = []
        max_len = max(len(a), len(b))
        a = a.zfill(max_len)
        b = b.zfill(max_len)

        for i in range(max_len - 1, -1, -1):
            sum_digits = int(a[i]) +int(b[i]) + carry
            result.append(str(sum_digits % 2))
            carry = sum_digits // 2

        if carry:
            result.append('1')

        return ''.join(reversed(result))
