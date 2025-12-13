/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30203
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int l = mid, r = mid;
                while (l >= 1 && nums[l - 1] == target) {
                    l--;
                }
                while (r <= n - 2 && nums[r + 1] == target) {
                    r++;
                }
                return {l, r};
            }
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};
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

