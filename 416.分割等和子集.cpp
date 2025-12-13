/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30203
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        cout << target;
        // dp[i] 定义为 能否用前i个数（0 - i-1）塞满背包（大小为j）
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
            // if (i - 1 >= 0 && nums[i - 1] <= target) {
            //     for (int j = i; j <= n; j++) {
            //         dp[j][nums[i - 1]] = true;
            //     }
            // }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (i < 1) {
                    continue;
                }
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // cout << dp[1][1] ? 1 : 0 << '\n';
        // cout << dp[2][1] ? 1 : 0 << '\n';
        // cout << dp[2][11] ? 1 : 0 << '\n';
        // cout << dp[3][11] ? 1 : 0 << '\n';
        // cout << dp[4][11] ? 1 : 0 << '\n';
        return dp[n][target];
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,5,10,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

