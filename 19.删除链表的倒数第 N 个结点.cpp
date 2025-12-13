/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30203
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        ListNode* node = &dummy;
        node->next = head;
        ListNode* left = node, * right = node;
        while (n--) {
            right = right->next;
        }
        while (right->next) {
            right = right->next;
            left = left->next;
        }
        ListNode* next = left->next->next;
        left->next = next;
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

