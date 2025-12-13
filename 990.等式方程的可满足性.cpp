/*
 * @lc app=leetcode.cn id=990 lang=cpp
 * @lcpr version=30203
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class UF {
private:
    vector<int> parent;
    vector<int> size;
    int count_;

public:
    UF(int cnt) {
        this->count_ = cnt;
        parent.resize(cnt);
        size.resize(cnt, 1);
        for (int i = 0; i < cnt; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        int root = findParent(parent[x]);
        parent[x] = root;
        return parent[x];
    }

    void unionNode(int p, int q) {
        int root_p = findParent(p);
        int root_q = findParent(q);
        if(root_p == root_q) {
            return;
        }

        parent[root_p] = root_q;
        count_--;
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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (auto eq : equations) {
            if (eq[1] == '=') {
                uf.unionNode(eq[0] - 'a', eq[3] - 'a');
            }
        }

        for (auto eq : equations) {
            if (eq[1] == '!') {
                if (uf.isConnected(eq[0] - 'a', eq[3] - 'a')) {
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
// b"\na"]\n
// @lcpr case=end

// @lcpr case=start
// a"\nb"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\nc"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\na"]\n
// @lcpr case=end

// @lcpr case=start
// c"\nd"\nz"]\n
// @lcpr case=end

 */

