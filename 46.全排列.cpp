/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30203
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        used.resize(n, false);
        backtrack(nums);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        if (track.size() > nums.size()) {
            return;
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (used[i] == true) {
                continue;
            }
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums);
            used[i] = false;
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

