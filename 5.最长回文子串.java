/*
 * @lc app=leetcode.cn id=5 lang=java
 * @lcpr version=30304
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        String res = new String();
        for (int i = 0; i < s.length(); i++) {
            String s1 = fromIToBothSide(i, i, s);
            String s2 = fromIToBothSide(i, i + 1, s);
            String s3 = s1.length() > s2.length() ? s1 : s2;
            res = res.length() > s3.length() ? res : s3;
        }
        return res;
    }

    private String fromIToBothSide(int left, int right, String s) {
        if (left < 0 || right >= s.length()) {
            return new String();
        }
        if (s.charAt(left) != s.charAt(right)) {
            return s.substring(left, left + 1);
        }
        for (; left >= 0 && right < s.length(); left--, right++) {
            if (s.charAt(left) != s.charAt(right)) {
                break;
            }
        }
        System.out.println(left + " " + right);
        return s.substring(left + 1, right);
    }
}
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

 */

