/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30203
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] < target) {
                continue;
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == target) {
                    return true;
                } else if (matrix[i][j] < target) {
                    break;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */

