/*
 * @lc app=leetcode.cn id=1361 lang=cpp
 * @lcpr version=30203
 *
 * [1361] 验证二叉树
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
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        count_ = n;
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
        return root;
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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
            }
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root != -1) {
                    return false;
                }
                root = i;
            } else if (indegree[i] > 1) {
                return false;
            }
        }

        if (root == -1) {
            return false;
        }

        UF uf(n);
        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                if (uf.isConnected(i, left)) {
                    return false;
                }
                uf.unionNode(i, left);
            }
            if (right != -1) {
                if (uf.isConnected(i, right)) {
                    return false;
                }
                uf.unionNode(i, right);
            }
        }
        return true;
    }



    bool validateBinaryTreeNodes_indegree(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        if (q.size() > 1) {
            return false;
        }
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int node = q.front();
                q.pop();
                cnt++;
                if (leftChild[node] != -1) {
                    indegree[leftChild[node]]--;
                    if (indegree[leftChild[node]] != 0) {
                        return false;
                    }
                    q.push(leftChild[node]);
                }
                if (rightChild[node] != -1) {
                    indegree[rightChild[node]]--;
                    if (indegree[rightChild[node]] != 0) {
                        return false;
                    }
                    q.push(rightChild[node]);
                }
            }
        }
        return cnt == n;
    }


    bool validateBinaryTreeNodes_imperfect(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UF uf(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1){
                if (uf.isConnected(i, leftChild[i])) {
                    return false;
                }
                uf.unionNode(i, leftChild[i]);
            }
            if (rightChild[i] != -1){
                if (uf.isConnected(i, rightChild[i])) {
                    return false;
                }
                uf.unionNode(i, rightChild[i]);
            }
        }
        return uf.getCount() == 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[1,-1,3,-1]\n[2,-1,-1,-1]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,-1,3,-1]\n[2,3,-1,-1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,0]\n[-1,-1]\n
// @lcpr case=end

 */

