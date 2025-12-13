/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30203
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 定义dp[i][j]为从（0，0）到（i - 1，j - 1）的最短距离
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unsigned>> dp(m + 1, vector<unsigned>(n + 1, INT_MAX));
        dp[1][1] = grid[0][0];
        for (int i = 2; i < m; i++) {
            dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
        }
        for (int j = 2; j < n; j++) {
            dp[1][j] = dp[1][j - 1] + grid[0][j - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], 
                    grid[i - 1][j - 1] + 
                    min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

