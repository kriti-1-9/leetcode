class Solution(object):
    def sortVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = 'aeiouAEIOU'
        temp = []
        for i in s:
            if i in vowels:
                temp.append(i)
        temp.sort()
        j = 0
        for i in range(len(s)):
            if s[i] in vowels:
                s = s[:i] + temp[j] + s[i+1:]
                j += 1
        return s