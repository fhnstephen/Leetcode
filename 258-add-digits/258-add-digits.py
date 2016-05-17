class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        # while num >= 10:
        #     next = 0
        #     while num > 0:
        #         next = next + num % 10
        #         num = num // 10
        #     num = next
        # return num
        if num == 0:
            return num
        else:
            ans = num % 9
            if ans == 0:
                return 9
            else:
                return ans