/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *tmp = new ListNode();
        tmp->next = head;

        ListNode *fast = tmp, *slow = tmp;
        for(int i=0;i<n;i++)
        fast = fast->next;
        while(fast->next)
        {
            slow = slow->next;
            fast=fast->next;
        }
        ListNode *pivot = slow->next;
        slow->next = slow->next->next;
        delete pivot;
        return tmp->next;
    }
};
// @lc code=end
