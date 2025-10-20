class Solution(object):
    def finalValueAfterOperations(self, operations):
        nums = 0
        for i in operations:
            if i == "++X" or i == "X++":
                nums += 1
            else:
                nums -= 1
        return nums