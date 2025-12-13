/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30203
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                swap(matrix[j][i], matrix[j][n - i - 1]);
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

