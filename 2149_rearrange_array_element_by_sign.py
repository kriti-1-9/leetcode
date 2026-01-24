class Solution(object):
    def rearrangeArray(self, nums):
        arr = [i for i in nums]
        pos = 0
        neg = 1
        for i in nums:
            if i > 0:
                arr[pos] = i
                pos += 2
            else:
                arr[neg] = i
                neg += 2
        return arr