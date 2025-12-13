/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30203
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        curr->next = head;
        while (curr->next && curr->next->next) {
            ListNode* node1 = curr, *node2 = node1->next, *node3 = node2->next, *node4 = node3->next;
            node3->next = node2;
            node2->next = node4;
            node1->next = node3;
            curr = node2;
        }
        ListNode* res = &dummy;
        return res->next;

    }
//  prev    curr    succ    next
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

