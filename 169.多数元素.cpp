/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30203
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (curr == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                curr = nums[i];
                cnt = 1;
            }
        }
        return curr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

