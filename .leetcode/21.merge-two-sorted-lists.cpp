/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *tail = head;
        ListNode *tmp1 = list1, *tmp2 = list2;
        while (tmp1 && tmp2)
        {
            if(tmp1->val <= tmp2->val)
            {
                tail->next = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
            }
            else
            {
                tail->next = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
            }
            tail = tail->next;
        }
        if (tmp1)
            tail->next = tmp1;
        else if(tmp2)
            tail->next = tmp2;
        return head->next;
    }
};
// @lc code=end
