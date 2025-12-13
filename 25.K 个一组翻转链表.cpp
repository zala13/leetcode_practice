/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30203
 *
 * [25] K 个一组翻转链表
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        bool flag = true;
        ListNode* prev = &dummy;
        while (flag && prev && prev->next) {
            ListNode* curr = prev->next;
            int n = k;
            for (int i = 1; i < n; i++) {
                if (curr->next) {
                    curr = curr->next;
                } else {
                    flag = false;
                }
            }
            if (flag) {
                ListNode* next_group_start = curr->next;
                ListNode* this_group_start = prev->next;
                curr = this_group_start;
                ListNode* next = curr->next;
                for (int i = 1; i < n; i++) {
                    ListNode* next_start = next->next;
                    next->next = curr;
                    curr = next;
                    next = next_start;
                }
                prev->next = curr;
                this_group_start->next = next_group_start;
                prev = this_group_start;
            } else {
                break;
            }
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

