/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30203
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        if (head->next == nullptr) {
            return true;
        }
        // 找到中点
        ListNode* slow = head, * fast = head;
        int x = 0;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            x++;
        }
        
        // 反转第二段链表
        if (fast->next == nullptr) {
            // 奇数，中间有一个节点不用管
        } else {
            // 偶数
            fast = fast->next;
            x += 1;
        }
        ListNode* pre = nullptr, * cur = slow->next;
        cout << slow->val << ' ' << cur->val;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        ListNode* left = head, * right = fast;
        // 判断前后是否相等
        while (x--) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

