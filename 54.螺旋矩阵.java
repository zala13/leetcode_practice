/*
 * @lc app=leetcode.cn id=54 lang=java
 * @lcpr version=30305
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (up <= down || left <= right) {
            // 在第 up 行遍历，关注左右
            for (int x = left; x <= right && up <= down; x++) {
                res.add(matrix[up][x]);
            }
            up++;

            // 在第 right 列进行遍历,关注上下
            for (int y = up; y <= down && left <= right; y++) {
                res.add(matrix[y][right]);
            }
            right--;

            // 在第 up 行遍历，关注左右
            for (int x = right; x >= left && up <= down; x--) {
                res.add(matrix[down][x]);
            }
            down--;

            // 在第 right 列进行遍历,关注上下
            for (int y = down; y >= up && left <= right; y--) {
                res.add(matrix[y][left]);
            }
            left++;
        }
        return res;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

