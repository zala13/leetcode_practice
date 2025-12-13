/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30203
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(vector<int>& nums, int start) {
        int n = nums.size();
        if (start <= n) {
            res.push_back(track);
        } else {
            return;
        }
        
        for (int i = start; i < n; i++) {
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
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
// [0]\n
// @lcpr case=end

 */

