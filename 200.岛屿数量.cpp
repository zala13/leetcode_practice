/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30203
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    res++;
                    backtrack(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    vector<vector<bool>> visited;
    void backtrack(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (visited[i][j] || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        grid[i][j] = 0;

        backtrack(grid, i - 1, j);
        backtrack(grid, i + 1, j);
        backtrack(grid, i, j - 1);
        backtrack(grid, i, j + 1);
    }

};
// @lc code=end



/*
// @lcpr case=start
// [\n['1','1','1','1','0'],\n['1','1','0','1','0'],\n['1','1','0','0','0'],\n['0','0','0','0','0']\n]\n
// @lcpr case=end

// @lcpr case=start
// [\n['1','1','0','0','0'],\n['1','1','0','0','0'],\n['0','0','1','0','0'],\n['0','0','0','1','1']\n]\n
// @lcpr case=end

 */

