/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30203
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int hei = INT_MAX;
        int area = 0;
        // 定义为以i结尾的最长面积
        // vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            hei = heights[i];
            for (int j = i; j >= 0; j--) {
                hei = min(hei, heights[j]);
                area = max(area, hei * (i - j + 1));
            }
        }
        return area;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */

