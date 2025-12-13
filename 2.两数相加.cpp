/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30203
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, * p2 = l2;
        int pluse = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (p1 != nullptr || p2 != nullptr || pluse > 0) {
            int val = pluse;
            if (p1 != nullptr) {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                val += p2->val;
                p2 = p2->next;
            }
            pluse = val / 10;
            p->next = new ListNode(val % 10);;
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

