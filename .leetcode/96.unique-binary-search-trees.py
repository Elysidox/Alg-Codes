# @before-stub-for-debug-begin
from python3problem96 import *
from typing import *

# @before-stub-for-debug-end

#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#


# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        numList = [1, 1]
        for i in range(2, n + 1):
            num = 0
            for j in range(i):
                num += numList[j] * numList[i - j - 1]
            numList.append(num)
        return numList[n]


# @lc code=end
