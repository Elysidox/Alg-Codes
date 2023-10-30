#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for index, value in enumerate(nums):
            if target - value in hashmap:
                return [hashmap[target - value], index]
            hashmap[value] = index
        return []

# @lc code=end
