/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30203
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
private:
    vector<bool> visited;
    vector<bool> onPath;
    vector<int> path;
    bool isCircled = false;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        vector<int> path;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                path.push_back(node);
                count++;
                for (auto point : graph[node]) {
                    indegree[point]--;
                    if (indegree[point] == 0) {
                        q.push(point);
                    }
                }
            }
        }
        if (count < numCourses) {
            return vector<int>();
        }
        return path;
    }


    vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }

        visited.resize(numCourses, false);
        onPath.resize(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (isCircled) {
                break;
            }
            traverse(graph, i);
        }

        if (isCircled) {
            return vector<int>();
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void traverse(vector<vector<int>>& graph, int idx) {
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
            traverse(graph, point);
        }
        path.push_back(idx);
        onPath[idx] = false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

