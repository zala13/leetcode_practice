/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30203
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0, n);
        return res;
    }

private:
    vector<string> res;
    string track = "";
    int left = 0, right = 0;
    void backtrack(int idx, int n) {
        if (left < right) {
            return;
        }
        if (idx > 2 * n) {
            return;
        }
        if (left + right == 2 * n && left == right) {
            res.push_back(track);
            return;
        }

        left++;
        track += '(';
        backtrack(idx + 1, n);
        left--;
        track.pop_back();

        right++;
        track += ')';
        backtrack(idx + 1, n);
        right--;
        track.pop_back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

