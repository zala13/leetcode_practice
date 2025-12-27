/*
 * @lc app=leetcode.cn id=62 lang=java
 * @lcpr version=30305
 *
 * [62] 不同路径
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    int[][] memo;
    public int uniquePaths(int m, int n) {
        memo = new int[m][n];
        for (int[] row : memo) {
            Arrays.fill(row, 0);
        }
        
        return backtrack(m, n, 0, 0);
    }

    private int backtrack(int m, int n, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m-1 && j == n-1) {
            return 1;
        }
        if (memo[i][j] > 0) {
            return memo[i][j];
        }

        memo[i][j] += backtrack(m, n, i+1, j);
        memo[i][j] += backtrack(m, n, i, j+1);
        return memo[i][j];
    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */

