/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30203
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && matrix[i][j] == 0) {
                    visited[i][j] = true;
                    flood(matrix, i, j); 
                }
            }
        }
    }

private:
    vector<vector<bool>> visited;
    void flood(vector<vector<int>>& matrix, int row, int col) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (!visited[i][col] && matrix[i][col] != 0) {
                matrix[i][col] = 0;
                visited[i][col] = true;
            }
        }
        for (int j = 0; j < n ; j++) {
            if (!visited[row][j] && matrix[row][j] != 0) {
                matrix[row][j] = 0;
                visited[row][j] = true;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */

