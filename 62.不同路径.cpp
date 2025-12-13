/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30203
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        memo.resize(m + 1, vector<int>(n + 1, -1));
        return backtrack(m, n, 0, 0);
    }

private:
    int res = 0;
    vector<vector<int>> memo;
    int backtrack(int m, int n, int r, int c) {
        if (r == m - 1 && c == n - 1) {
            return 1;
        }
        if (r > m - 1 || c > n - 1 || r < 0 || c < 0) {
            return 0;
        }
        if (memo[r][c] != -1) {
            return memo[r][c];
        }
        // 下
        memo[r][c] = backtrack(m, n, r, c + 1) + backtrack(m, n, r + 1, c);
        
        return memo[r][c];
    }

};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

