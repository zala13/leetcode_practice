/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30203
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        memo.resize(n, -1);
        return backtrack(n, 0);
    }

private:
    vector<int> memo;
    int backtrack(int n, int cur) {
        if (cur == n) {
            return 1;
        }
        if (cur > n) {
            return 0;
        }
        if (memo[cur] != -1) {
            return memo[cur];
        }
        memo[cur] = backtrack(n, cur + 1) + backtrack(n, cur + 2);
        return memo[cur];
    }

};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

