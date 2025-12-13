/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30203
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, 0, target);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(vector<int>& candidates, int idx, int sum, int target) {
        int n = candidates.size();
        if (sum == target) {
            res.push_back(track);
            return;
        }
        if (sum > target) {
            return;
        }
        if (idx == n) {
            return;
        }

        for (int i = idx; i < n; i++) {
            // cout << i << ' ';
            track.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, i, sum, target);
            sum -= candidates[i];
            track.pop_back();
        }
    }


};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

