/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30203
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int tmp = nums[i - 1];
            dp[i][0] = max({tmp, tmp * dp[i - 1][0], tmp * dp[i - 1][1]});
            dp[i][1] = min({tmp, tmp * dp[i - 1][0], tmp * dp[i - 1][1]});
            // cout << 
            res = max(res, dp[i][0]);

        }
        return res;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

