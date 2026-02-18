class Solution(object):
    def hasAlternatingBits(self, n):
        ans = str(bin(n))
        for i in range(1, len(ans)):
            if ans[i-1] == ans[i]:
                return False
        return True