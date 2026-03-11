class Solution(object):
    def bitwiseComplement(self, n):
        if n == 0:
            return 1
        ans = ""
        while(n > 0):
            if n % 2 == 0:
                ans += '1'
            else:
                ans += '0'
            n //= 2
        p = 0
        a = 0
        for i in ans:
            if i == '1':
                a += 2 ** p
            p += 1
        return a