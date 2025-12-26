/*
 * @lc app=leetcode.cn id=51 lang=java
 * @lcpr version=30305
 *
 * [51] N 皇后
 */

// @lc code=start

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        List<String> track = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            track.add(".".repeat(n));
        }
        backtrack(track, 0);
        return res;
    }

    private void backtrack(List<String> track, int row) {
        if (row == track.size()) {
            res.add(new ArrayList<>(track));
            return;
        }
        int n = track.size();
        for (int col = 0; col < n; col++) {
            if (willFight(track, row, col)) {
                continue;
            }
            char[] newRow = track.get(row).toCharArray();
            newRow[col] = 'Q';
            track.set(row, new String(newRow));
            // 这里体现为什么传行数，即 row，可以自动避免同一行
            backtrack(track, row + 1);
            newRow[col] = '.';
            track.set(row, new String(newRow));
        }
    }

    private boolean willFight(List<String> track, int row, int col) {
        int n = track.size();
        // 列
        for (int i = 0; i < row; i++) {
            if (track.get(i).charAt(col) == 'Q') {
                return true;
            }
        }
        // 左上方
        for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
            if (track.get(x).charAt(y) == 'Q') {
                return true;
            }
        }
        // 右上方
        for (int x = row, y = col; x >= 0 && y < n; x--, y++) {
            if (track.get(x).charAt(y)== 'Q') {
                return true;
            }
        }

        return false;
    }
}
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

