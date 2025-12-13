/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30203
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int res = nums[0];
        if (res < nums[n - 1]) {
            return res;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            }
            if (nums[mid] <= nums[n - 1]) {
                right = mid - 1;
            }

        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */

