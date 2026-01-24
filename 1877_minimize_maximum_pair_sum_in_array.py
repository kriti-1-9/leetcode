class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort() # n log n
        st = 0
        end = len(nums) - 1
        ans = 0
        while(st < end):
            ans = max(ans, nums[st] + nums[end])
            st += 1
            end -= 1
        return ans