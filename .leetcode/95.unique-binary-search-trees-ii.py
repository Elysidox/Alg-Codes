#
# @lc app=leetcode id=95 lang=python3
#
# [95] Unique Binary Search Trees II
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def generateTrees(start, end):
            if start > end:
                return [
                    None,
                ]

            allTrees = []
            for i in range(start, end + 1):
                leftTrees = generateTrees(start, i - 1)
                rightTrees = generateTrees(i + 1, end)

                for l in leftTrees:
                    for r in rightTrees:
                        newNode = TreeNode(i)
                        newNode.left = l
                        newNode.right = r
                        allTrees.append(newNode)

            return allTrees

        return generateTrees(1, n) if n else []


# @lc code=end
