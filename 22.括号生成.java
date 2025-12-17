/*
 * @lc app=leetcode.cn id=22 lang=java
 * @lcpr version=30305
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        trackback(n, 0, 0, new StringBuilder());
        return res;
    }

    private void trackback(int n, int left, int right, StringBuilder track) {
        if (right > left || left > n || right > n) {
            return;
        }
        if (left == n && right == n) {
            res.add(track.toString());
            return;
        }
        
        track.append('(');
        trackback(n, left + 1, right, track);
        track.deleteCharAt(track.length() - 1);

        track.append(')');
        trackback(n, left, right + 1, track);
        track.deleteCharAt(track.length() - 1);

    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

