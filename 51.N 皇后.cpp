/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30203
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        track.resize(n, string(n, '.'));
        backtrack(n, 0);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<string> track; 
    int Q = 0;
    void backtrack(int n, int idx) {
        int row = idx / n;
        int col = idx % n;
        if (Q == n) {
            res.push_back(track);
            return;
        }
        if (idx >= n * n) {
            return;
        }
        
        // 放皇后
        if (isValid(track, row, col)) {
            track[row][col] = 'Q';
            Q++;
            backtrack(n, idx + 1);
            track[row][col] = '.';
            Q--;
        } 

        // 不放皇后
        backtrack(n, idx + 1);
    }

    bool isValid(vector<string>& matrix, int r, int c) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            if (matrix[i][c] == 'Q' || matrix[r][i] == 'Q') {
                return false;
            }
        }
        // 对角线的判断条件！
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 'Q' &&
                    abs(r - i) == abs(c - j)) {
                        return false;
                    }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

