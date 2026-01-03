class Solution(object):
    def searchInsert(self, nums, target):
        low=0
        high=len(nums)-1
        while(high>=low):
            if high==low:
                if target<=nums[low]:
                    return low
                else:
                    return low+1
            mid=low+(high-low)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                high=mid-1
            else:
                low=mid+1
        return low
        