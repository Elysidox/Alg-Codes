#
# @lc app=leetcode id=1678 lang=python3
#
# [1678] Goal Parser Interpretation
#


# @lc code=start
class Solution:
    def interpret(self, command: str) -> str:
        n = len(command)
        res, i = "", 0
        while i < n:
            # print(command[i])
            if command[i] == "G":
                res += "G"
                i += 1
            else:
                if command[i + 1] == ")":
                    res += "o"
                    i += 2
                else:
                    res += "al"
                    i += 4
        return res


# @lc code=end
