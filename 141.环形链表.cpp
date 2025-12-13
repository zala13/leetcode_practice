/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30203
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (slow == nullptr || fast == nullptr || fast->next == nullptr || fast->next->next == nullptr) {
            return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

