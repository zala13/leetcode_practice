/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30203
 *
 * [31] 下一个排列
 */

// 147432123321
// 147432123321
//        3 3221
//        31223
//        13321
//        2 3311
//        21133
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                right = i;
                left = i - 1;
                break;
            }
        }
        if (left != -1) {
            // 先找到第一个比减小的值大的，注意不一定是相邻的
            int idx = right;
            for (int i = n - 1; i >= right; i--) {
                if (nums[i] > nums[left]) {
                    idx = i;
                    break;
                }
            }
            // 找到后进行交换，然后在对之后的数组进行排序
            int tmp = nums[left];
            nums[left] = nums[idx];
            nums[idx] = tmp;
            sort(nums.begin() + left + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

