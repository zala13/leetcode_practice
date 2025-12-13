/*
 * @lc app=leetcode.cn id=886 lang=cpp
 * @lcpr version=30203
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (auto edge : dislikes) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        return isBipartite(graph);
    }

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
// 4\n[[1,2],[1,3],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,2],[2,3],[3,4],[4,5],[1,5]]\n
// @lcpr case=end

 */

