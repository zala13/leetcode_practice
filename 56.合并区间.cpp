/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30203
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;

        for (auto interval : intervals) {
            pq.push(interval);
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            vector<int> tmp1 = pq.top();
            pq.pop();
            cout << tmp1[0] << ' ' << tmp1[1] << '|';
            if (pq.empty()) {
                res.push_back(tmp1);
                continue;
            }
            vector<int> tmp2 = pq.top();
            pq.pop();
            cout << tmp2[0] << ' ' << tmp2[1] << '|';
            
            if (tmp2[0] <= tmp1[1]) {
                vector<int> tmp(2);
                tmp[0] = min(tmp1[0], tmp2[0]);
                tmp[1] = max(tmp1[1], tmp2[1]);
                pq.push(tmp);
            } else {
                res.push_back(tmp1);
                pq.push(tmp2);
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */

