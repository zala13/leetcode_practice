/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30203
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // 定义为 
        // word1 的前i个(0 - i-1)字符
        // 变成
        // word2 的前j个(0 - j-1)字符
        // 一模一样所需的最小操作数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                } else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,
                        dp[i][j - 1] + 1,
                        dp[i - 1][j - 1] + 1
                    });
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

