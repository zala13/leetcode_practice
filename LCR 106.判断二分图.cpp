/*
 * @lc app=leetcode.cn id=LCR 106 lang=cpp
 * @lcpr version=30203
 *
 * [LCR 106] 判断二分图
 */

// @lc code=start
class Solution {
private:
    bool ok = true;
    vector<bool> color;
    vector<bool> visited;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n, false);
        visited.resize(n, false);

        for (int i = 0; i < n; i++) {
            traverse2(graph, i);
        }

        return ok;
    }

    void traverse(vector<vector<int>>& graph, int idx) {
        if (idx >= graph.size()) {
            return;
        }

        if (!ok || visited[idx]) {
            return;
        }
        visited[idx] = true;
        for (auto p : graph[idx]) {
            if (visited[p]) {
                if (color[p] == color[idx]) {
                    ok = false;
                }
            } else {
                color[p] = !color[idx];
                traverse(graph, p);
            }
        }
    }

    void traverse2(vector<vector<int>>& graph, int idx) {
        if (idx >= graph.size()) {
            return;
        }

        if (!ok || visited[idx]) {
            return;
        }

        queue<int> q;
        q.push(idx);
        visited[idx] = true;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                for (auto point : graph[node]) {
                    if (visited[point]) {
                        if (color[point] == color[node]) {
                            ok = false;
                            return;
                        }
                    } else {
                        q.push(point);
                        visited[point] = true;
                        color[point] = !color[node];
                    }
                }
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */

