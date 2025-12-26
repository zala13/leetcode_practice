/*
 * @lc app=leetcode.cn id=55 lang=java
 * @lcpr version=30305
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) {
            return true;
        }
        int maxDist = 0;
        int step = 0;
        int nextDist = nums[0];
        for (int i = 0; i < nums.length; i++) {
            int curDist = nums[i] + i;
            maxDist = Math.max(maxDist, curDist);
            if (i == nextDist) {
                if (nextDist == maxDist && maxDist < nums.length - 1) {
                    return false;
                }
                nextDist = maxDist;
                step++;
            }
        }
        return true;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

