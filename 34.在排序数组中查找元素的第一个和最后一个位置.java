/*
 * @lc app=leetcode.cn id=34 lang=java
 * @lcpr version=30305
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                while (nums[left] != target && left <= mid) {
                    left++;
                }
                while (nums[right] != target && right >= mid) {
                    right--;
                }
                return new int[]{left, right};
            } else if (nums[mid] < target) {
                if (nums[left] < target && left <= mid) {
                    left++;
                }
            } else if (nums[mid] > target) {
                if (nums[right] > target && mid <= right) {
                    right--;
                }
            }
        }
        return new int[]{-1, -1};
    }
}
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

