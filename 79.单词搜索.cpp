/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30203
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    vector<vector<bool>> visited;
    bool backtrack(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) {
            return false;
        }
        if (idx >= word.size()) {
            return false;
        }
        if (visited[i][j]) {
            return false;
        }
        if (board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        if (
            backtrack(board, i + 1, j, word, idx + 1) ||
            backtrack(board, i - 1, j, word, idx + 1) ||
            backtrack(board, i, j + 1, word, idx + 1) ||
            backtrack(board, i, j - 1, word, idx + 1)
        ) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCB"\n
// @lcpr case=end

 */

