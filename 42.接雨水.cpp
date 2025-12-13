/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30203
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n = height.size();
        vector<int> max_l(n, 0);
        vector<int> max_r(n, 0);
        max_l[0] = height[0];
        max_r[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            max_l[i] = max(max_l[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            max_r[i] = max(max_r[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            res += min(max_l[i], max_r[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

