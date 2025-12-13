/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30203
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int n = nums.size();
        int res = -10001;
        while (right < n && left < n) {
            while (sum < 0 && left <= right) {
                sum -= nums[left];
                left++;
            }
            
            sum += nums[right];
            right++;
            res = max(sum, res);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

