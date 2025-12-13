/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30203
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<bool> visited;
    bool isCircled = false;

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        visited.resize(n, false);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                cnt++;
                for (auto point : graph[node]) {
                    indegree[point]--;
                    if (indegree[point] == 0) {
                        q.push(point);
                    }
                }

            }
        }

        if (cnt < n) {
            return false;
        }
        return true;
    }


    bool canFinish2(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        visited.resize(n, false);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }

        vector<bool> onPath(n, false);
        for (int i = 0; i < n; i++) {
            if (isCircled) {
                break;
            }
            traverse(graph, i, onPath);
        }

        return !isCircled;
    }

    void traverse(vector<vector<int>>& graph, int idx, vector<bool>& onPath) {
        if (isCircled) {
            return;
        }

        if (onPath[idx]) {
            isCircled = true;
            return;
        }
        
        if (visited[idx]) {
            return;
        }

        visited[idx] = true;
        onPath[idx] = true;
        for (auto point : graph[idx]) {
            traverse(graph, point, onPath);
        }
        onPath[idx] = false;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

