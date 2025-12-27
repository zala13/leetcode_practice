/*
 * @lc app=leetcode.cn id=64 lang=java
 * @lcpr version=30305
 *
 * [64] 最小路径和
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    int[][] memo;
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        memo = new int[m][n];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return backtrack(grid, m - 1, n - 1);
    }

    private int backtrack(int[][] grid, int i, int j) {
        int m = grid.length, n = grid[0].length;
        if (i == 0 && j == 0) {
            return grid[0][0];
        }
        if (i < 0 || j < 0) {
            return Integer.MAX_VALUE;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        } 
        

        int right = backtrack(grid, i-1, j);
        int down = backtrack(grid, i, j-1);
        memo[i][j] = grid[i][j] + Math.min(right, down);
        return memo[i][j];

    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

