/*
 * @lc app=leetcode.cn id=25 lang=java
 * @lcpr version=30305
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy, curr = head;
        while (curr!= null) {
            ListNode succ = prev;
            int cnt = 0;
            while (cnt < k) {
                if (succ.next == null) {
                    break;
                }
                succ = succ.next;
                cnt++;
            }
            if (cnt != k) {
                break;
            }
            succ = succ.next;

            ListNode start = prev;
            ListNode end = prev.next;
            prev = prev.next;
            curr = curr.next;
            while (curr != succ) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            start.next = prev;
            end.next = succ;
            prev = end;
            curr = prev.next;
        }
        return dummy.next;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

