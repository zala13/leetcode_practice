/*
 * @lc app=leetcode.cn id=547 lang=cpp
 * @lcpr version=30203
 *
 * [547] 省份数量
 */

// @lc code=start
class UF {
private:
    vector<int> parent;
    vector<int> size;
    int count_;

public:
    UF(int n) {
        parent.resize(n);
        size.resize(n, 1);
        this->count_ = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void unionNode(int p, int q) {
        int root_p = findParent(p);
        int root_q = findParent(q);
        if (root_p == root_q) {
            return;
        }
        parent[root_p] = root_q;
        size[root_p] += size[root_q];
        size[root_q] = size[root_p];
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

    int getCount() {
        return count_;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (isConnected[i][j] == 1) {
                    uf.unionNode(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */

