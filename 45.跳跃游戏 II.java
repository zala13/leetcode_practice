/*
 * @lc app=leetcode.cn id=45 lang=java
 * @lcpr version=30305
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        if (nums.length <= 1) {
            return 0;
        }
        int maxDist = 0, end = 0;
        int step = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxDist = Math.max(nums[i] + i, maxDist);
            if (i == end) {
                step++;
                end = maxDist;
                if (maxDist >= nums.length - 1) {
                    return step;
                }
            }
        }
        return -1;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

