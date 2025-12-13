/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30203
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (s.size() == 1) {
            return s;
        }
        for (int i = 0; i < n - 1; i++) {
            find_lps(s, i, i);
            find_lps(s, i, i + 1);
        }
        return res;
    }

private:
    string res = "";
    void find_lps(string& s, int left, int right) {
        string track = "";
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            track = s.substr(left, right - left + 1);
            left--;
            right++;
        }
        res = res.size() < track.size() ? track : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

