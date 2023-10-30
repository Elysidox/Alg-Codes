#
# @lc app=leetcode id=50 lang=python3
#
# [50] Pow(x, n)
#


# @lc code=start
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        if n == -1:
            return 1 / x
        if n % 2 == 0:
            tmp = self.myPow(x, n / 2)
            return tmp * tmp
        if n % 2 == 1:
            tmp = self.myPow(x, n // 2)
            return tmp * tmp * x


# @lc code=end
