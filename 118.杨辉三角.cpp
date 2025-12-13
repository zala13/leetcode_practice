/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30203
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums(numRows);
        for (int i = 0; i < numRows; i++) {
            nums[i].resize(i + 1, 0);
            nums[i][0] = 1;
            nums[i][i] = 1;
            for (int j = 1; j < i; j++) {
                nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
            }
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

