/*
 * @lc app=leetcode.cn id=3 lang=java
 * @lcpr version=30304
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        HashMap<Character, Integer> window = new HashMap<>();
        int maxLength = 0;
        int left = 0, right = 0;
        for ( ; right < s.length(); right++) {
            char curChar = s.charAt(right);
            window.put(curChar, window.getOrDefault(curChar, 0) + 1);
            while (window.get(curChar) > 1 && left <= right) {
                char deleteChar = s.charAt(left);
                window.put(deleteChar, window.get(deleteChar) - 1);
                left++;
            }
            maxLength = Math.max(right - left + 1, maxLength);
            
        }
        return maxLength;
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

 */

