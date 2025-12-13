/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30203
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
            if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                i--;
                right--;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

