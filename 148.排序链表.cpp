/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30203
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        // 分治
        if (!head) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* left = head, * right = head;
        while (right->next && right->next->next) {
            right = right->next->next;
            left = left->next;
        }
        ListNode* next = left->next;
        left->next = nullptr;
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(next);
        return mergeList(list1, list2);
    }

private:
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while (list1 && list2) {
            int val1 = list1->val;
            int val2 = list2->val;
            if (val1 <= val2) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        if (list1) {
            curr->next = list1;
        } else if (list2) {
            curr->next = list2;
        }

        ListNode* res = &dummy;
        return res->next;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

