/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30203
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int n = nums.size();
        int farthest = 0;
        int end = 0;
        bool flag = false;
        for (int i = 0; i <= farthest; i++) {
            end = nums[i] + i;
            if (end == i) {
                flag = false;
            }
            farthest = max(end, farthest);
            if (farthest >= n - 1) {
                return true;
            }
        }
        return flag;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

