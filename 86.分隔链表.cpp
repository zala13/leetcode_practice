/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30203
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1);
        ListNode* left = &dummy1;
        ListNode dummy2(-1);
        ListNode* right = &dummy2;
        ListNode* node = head;
        while (node) {
            if (node->val < x) {
                left->next = node;
                left = left->next;
            } else {
                right->next = node;
                right = right->next;
            }
            ListNode* next = node->next;
            node->next = nullptr;
            node = next;
        }
        left->next = dummy2.next;
        return dummy1.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */

