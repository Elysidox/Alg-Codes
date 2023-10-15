/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode;
        ListNode *cur = head, *cur1 = l1, *cur2 = l2;
        int sum = 0, carry = 0;
        while (cur1 || cur2)
        {
            // head->next = new ListNode;
            int x = (cur1) ? cur1->val : 0;
            int y = (cur2) ? cur2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (cur1)
                cur1 = cur1->next;
            if (cur2)
                cur2 = cur2->next;
        }
        if (carry)
            cur->next = new ListNode(carry);
        return head->next;
    }
};
// @lc code=end
