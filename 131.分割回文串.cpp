/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30203
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        if (n == 0) {
            return {{}};
        }
        if (n == 1) {
            track.push_back(s);
            res.push_back(track);
            return res;
        }
        memo.resize(n, vector<int>(n, -1));
        backtrack(s, 0);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<string> track;
    vector<vector<int>> memo;
    void backtrack(string& s, int start) {
        int n = s.size();
        if (start < 0 || start > n ) {
            return;
        }
        if (start == n) {
            res.push_back(track);
            return;
        }

        for (int i = start; i < n; i++) {
            if (!isP(s, start, i)) {
                continue;
            }
            track.push_back(s.substr(start, i + 1 - start));
            backtrack(s, i + 1);
            track.pop_back();
        }
    }

    bool isP(string& s, int left, int right) {
        if (memo[left][right] == 1) {
            return true;
        } else if (memo[left][right] == 0) {
            return false;
        }
        while (left < right ) {
            if (s[left] != s[right]) {
                memo[left][right] = 0;
                return false;
            }
            left++;
            right--;
        }
        memo[left][right] = 1;
        return true;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

