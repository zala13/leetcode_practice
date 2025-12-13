/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30203
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n, 1);
        front[0] = nums[0];
        for (int i = 1; i < n; i++) {
            front[i] = front[i - 1] * nums[i];
        }
        vector<int> back(n, 1);
        back[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            back[i] = back[i + 1] * nums[i];
        }
        vector<int> res(n, 1);
        res[0] = back[1];
        res[n - 1] = front[n - 2];
        for (int i = 1; i < n - 1; i++) {
            res[i] = front[i - 1] * back[i + 1];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

