class Solution(object):
    def binaryGap(self, n):
        s = bin(n)[2:]   # remove '0b'
        
        prev = -1
        max_gap = 0
        
        for i in range(len(s)):
            if s[i] == '1':
                if prev != -1:
                    max_gap = max(max_gap, i - prev)
                prev = i
        
        return max_gap