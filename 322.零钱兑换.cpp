/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30203
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 定义 dp[i] 为凑成金额 i 所需的最少硬币个数
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int m = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < m; j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

