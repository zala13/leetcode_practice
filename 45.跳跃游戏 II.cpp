/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30203
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = nums[0];
        int res = 0;
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= nums[0] && i < n; i++) {
            dp[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= nums[i] && i + j <= n - 1; j++) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
            
        }
        return dp[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

