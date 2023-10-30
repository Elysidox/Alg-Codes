#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#


# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        n = len(s)
        right, ans = -1, 0
        for i in range(n):
            if i != 0:
                char_set.remove(s[i - 1])
            while right < n - 1 and s[right + 1] not in char_set:
                char_set.add(s[right + 1])
                right += 1
            ans = max(right - i + 1, ans)
        return ans


# @lc code=end
