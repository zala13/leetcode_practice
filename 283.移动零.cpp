/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30203
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 1;
        int target = 0;
        while (left < right && right < n) {
            while (left < n && nums[left] != target) {
                left++;
            }
            right = left + 1;
            while (right < n && nums[right] == target) {
                right++;
            }
            if (left < n && right < n && nums[left] == target && nums[right] != target) {
                swap(nums[left], nums[right]);
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

