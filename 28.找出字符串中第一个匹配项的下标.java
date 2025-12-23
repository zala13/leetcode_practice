/*
 * @lc app=leetcode.cn id=28 lang=java
 * @lcpr version=30305
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        int L = needle.length();
        int R = 256;
        long Q = 1658598167;
        long RL = 1;
        for (int i = 1; i <= L - 1; i++) {
            RL = (RL * R) % Q;
        }

        long needleHash = 0;
        for (int i = 0; i < needle.length(); i++) {
            needleHash = (R * needleHash + needle.charAt(i)) % Q;
        }

        long windowHash = 0;

        int left = 0, right = 0;
        while (right < haystack.length()) {
            windowHash = ((R * windowHash) % Q + haystack.charAt(right)) % Q;
            right++;

            if (right - left == L) {
                if (windowHash == needleHash) {
                    if (needle.equals(haystack.substring(left, right))) {
                        return left;
                    }
                }

                windowHash = (windowHash - (haystack.charAt(left) * RL) % Q + Q) % Q;
                left++;
            }
        }
        return -1;
    }
}
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

