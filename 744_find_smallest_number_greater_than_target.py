class Solution(object):
    def nextGreatestLetter(self, letters, target):
        for letter in letters:
            if letter > target:
                return letter
        return letters[0]