/*
 * @lc app=leetcode.cn id=41 lang=java
 * @lcpr version=30305
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
    public int firstMissingPositive(int[] nums) {
        // 0 - n-1 放 1 - n
        // 即 i+1 == nums[i] || i == nums[i - 1]
        for (int i = 0; i < nums.length; i++) {
            // 目前知道 nums[i] 的值，
            // 所以应该先把其放到下标为 nums[i] - 1 处
            while (nums[i] > 0  // 当前值大于0，否则无需移动
                && nums[i] - 1 < nums.length // 确保下标小于长度
                && nums[nums[i] - 1] != nums[i] // 当前点需要置换
            ) {
                swap(nums, i, nums[i] - 1);
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (i != nums[i] - 1) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }

    private void swap(int[] nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

