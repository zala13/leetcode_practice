/*
 * @lc app=leetcode.cn id=79 lang=java
 * @lcpr version=30305
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
    private boolean found = false;
    public boolean exist(char[][] board, String word) {
        if (word.length() == 0) {
            return true;
        }
        int m = board.length, n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    // visited[i][j] = true;
                    backtrack(board, visited, word, i, j, 0);
                    // visited[i][j] = false;
                }
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    private void backtrack(char[][] board, boolean[][] visited, String word, int i, int j, int idx) {
        if (idx == word.length()) {
            found = true;
            return;
        }
        if (i < 0 || j < 0 
            || i >= board.length || j >= board[0].length 
        ) {
            return;
        }
        if (found || visited[i][j]) {
            return;
        }
        if (board[i][j] != word.charAt(idx)) {
            return;
        }
        visited[i][j] = true;
        backtrack(board, visited, word, i + 1, j, idx + 1);
        backtrack(board, visited, word, i, j + 1, idx + 1);
        backtrack(board, visited, word, i - 1, j, idx + 1);
        backtrack(board, visited, word, i, j - 1, idx + 1);
        visited[i][j] = false;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

