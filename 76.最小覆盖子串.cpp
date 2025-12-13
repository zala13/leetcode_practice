/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30203
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int valid = 0;
        for (auto& ch : t) {
            need[ch]++;
        }
        int n = s.size();
        int left = 0, right = 0;
        bool find = false;
        // string res;
        int start, len = INT_MAX;
        while (left <= right && right <= n - 1)  {
            char ch = s[right];
            if (need.find(ch) != need.end()) {
                window[ch]++;
                if (need[ch] == window[ch]) {
                    valid++;
                }
            }
            while (valid == need.size() && left <= right) {
                // 更新答案
                if (!find) {
                    // res = s.substr(left, right - left + 1);
                    start = left;
                    len = right - left + 1;
                    find = true;
                }
                // res = res.size() < right - left + 1 ? res : s.substr(left, right - left + 1);;
                if (len > right - left + 1) {
                    start = left;
                    len = right - left + 1;
                }
                // 更新窗口
                if (need.find(s[left]) != need.end()) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]]) {
                        valid--;
                    }
                }
                left++;
            }
            while (need.find(s[left]) == need.end() && left <= right) {
                left++;
            }
            right++;
        }
        if (find) {
            return s.substr(start, len);
        }
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

