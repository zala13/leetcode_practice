/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30203
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        if (n == 1) {
            return lists[0];
        }
        ListNode* node1 = lists[0];
        ListNode* node2;
        for (int i = 1; i < n; i++) {
            node2 = lists[i];
            node1 = mergeTwoLists(node1, node2);
        }
        return node1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* node = &dummy;
        while (list1 && list2) {
            int val1 = list1->val;
            int val2 = list2->val;
            if (val1 < val2) {
                node->next = new ListNode(val1);
                list1 = list1->next;
            } else {
                node->next = new ListNode(val2);
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

