/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30203
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            res = max(res, area);
            if (height[right] < height[left]) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

