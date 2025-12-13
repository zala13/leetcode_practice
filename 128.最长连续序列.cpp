/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30203
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        for (int num : set) {
            if (set.find(num - 1) != set.end()) {
                continue;
            }

            int curNum = num;
            int curLen = 1;
            while (set.find(curNum + 1) != set.end()) {
                curNum += 1;
                curLen += 1;
            }
            res = max(res, curLen);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */

