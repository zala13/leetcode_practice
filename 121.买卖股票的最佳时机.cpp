/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30203
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][] 定义为在前i天（0 - i-1）交易股票获得的最大利润
        vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN));
        for (int i = 0; i <= n; i++) {
            if (i < 1) {
                dp[i][0] = 0;
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
        }
        return dp[n][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

