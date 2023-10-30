#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        '''
        if not root.left and not root.right:
            return [root.val]
        if not root.left:
            return [root.val] + self.inorderTraversal(root.right)
        if not root.right:
            return self.inorderTraversal(root.left) + [root.val]
        '''
        return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
# @lc code=end

