/*
 * @lc app=leetcode.cn id=53 lang=java
 * @lcpr version=30305
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int curSum = 0;
        int maxSum = nums[0];
        int left = 0, right = 0;
        int n = nums.length;
        while(right < n) {
            curSum += nums[right];
            right++;
            maxSum = Math.max(maxSum, curSum);
            while (curSum < 0 && left < right) {
                curSum -= nums[left];
                left++;
            }
        }
        return maxSum;
    }
}
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

