# @before-stub-for-debug-begin
from python3problem92 import *
from typing import *

# @before-stub-for-debug-end

#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        dummy_node = ListNode(-1)
        dummy_node.next = head
        pre = dummy_node
        for _ in range(left-1):
            pre = pre.next
        
        cur = pre.next
        for _ in range(right-left):
            suf = cur.next
            cur.next = suf.next
            suf.next = pre.next
            pre.next = suf
        
        return dummy_node.next
        '''
        if left == right:
            return head
        cur = head
        pre = ListNode(-1)
        pre.next = head
        pre_cur = pre
        for i in range(left - 1):
            cur = cur.next
            pre_cur = pre_cur.next
        left_bound = pre_cur
        right_bound = cur
        cur = cur.next
        pre_cur = pre_cur.next
        sufcur = cur.next
        for i in range(right - left):
            sufcur = cur.next
            cur.next = pre_cur
            pre_cur = cur
            cur = sufcur
        left_bound.next = pre_cur
        right_bound.next = sufcur
        return pre.next
        '''

# @lc code=end
