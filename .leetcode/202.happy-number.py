#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#


# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        res_set = set()
        while not n in res_set:
            res_set.add(n)
            sum = 0
            while n > 0:
                sum += (n % 10) * (n % 10)
                n = n // 10
            n = sum
            if n==1:
                return True
        return False


# @lc code=end
