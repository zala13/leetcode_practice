/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30203
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class UF {
private:
    int count_;
    vector<int> parent;

public:
    UF(int n) {
        this->count_ = n;
        this->parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionNode(int p, int q) {
        int root_p = findParent(p);
        int root_q = findParent(q);

        if (root_p == root_q) {
            return;
        }

        parent[root_q] = root_p;
        count_--;
    }

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        int root = findParent(parent[x]);
        parent[x] = root;

        return parent[x];
    }

    bool isConnected(int p, int q) {
        int root_p = findParent(p);
        int root_q = findParent(q);
        return root_p == root_q;
    }

    int count() {
        return count_;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        UF uf(m * n + 1);
        int dummy = m * n;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                // 首列
                uf.unionNode(i * n, dummy);
            }
            if (board[i][n - 1] == 'O') {
                uf.unionNode(i * n + n - 1, dummy);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                uf.unionNode(j, dummy);
            }
            if (board[m - 1][j] == 'O') {
                uf.unionNode(n * (m - 1) + j, dummy);
            }
        }

        vector<vector<int>> d{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O') {
                            uf.unionNode(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.isConnected(dummy, i * n + j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]\n
// @lcpr case=end

// @lcpr case=start
// [['X']]\n
// @lcpr case=end

 */

