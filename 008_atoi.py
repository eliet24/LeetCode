class Solution:
    def myatoi(self,s):
        num_ch = [str(i) for i in range(10)]
        s = s.strip()
        ret = ''
        if  not len(s): return 0
        if s[0] not in num_ch:
            if s[0] in ['-', '+'] and len(s[1:]) and s[1:][0] in num_ch:
                ret = ret + s[0]
                s = s[1:]
            else:
                return 0

        for c in s:
            if not c in num_ch: break
            else:
                ret = ret + c
        ret = int(ret)
        if ret < -pow(2,31):
            return -pow(2,31)
        if ret > pow(2,31) - 1:
            return pow(2,31)-1
        return ret

s = Solution()
print(s.myatoi("1234 hello"))
print(s.myatoi("hello 1234"))
print(s.myatoi("@ hello - 1234$%6"))
print(s.myatoi("-91283472332"))
