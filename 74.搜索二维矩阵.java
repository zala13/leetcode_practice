/*
 * @lc app=leetcode.cn id=74 lang=java
 * @lcpr version=30305
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int row = 0, col = n - 1;
        for (row = 0; row < m; row++) {
            if (matrix[row][col] < target) {
                continue;
            }
            for (int j = col; j >= 0; j--) {
                if (matrix[row][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */

