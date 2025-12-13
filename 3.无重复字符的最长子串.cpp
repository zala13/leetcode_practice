/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30203
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) {
            return 1;
        }
        int left = 0, right = 0;
        unordered_map<char, int> win;
        int cur = 0, res = 0;
        while (right < s.size()) {
            char ch = s[right];
            win[ch]++;
            while (win[ch] > 1) {
                win[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

