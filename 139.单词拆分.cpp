/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30203
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memo.resize(n, -1);
        return dp(s, wordDict, 0);
    }

private:
    bool found = false;
    vector<int> memo;
    bool dp(string s, vector<string>& wordDict, int idx) {
        int n = s.size();
        if (idx == n) {
            return true;
        }
        if (idx > n) {
            return false;
        }
        if (memo[idx] != -1) {
            return memo[idx] == 1 ? true : false;
        }

        for (auto& word : wordDict) {
            int len = word.size();
            if (idx + len > n) {
                continue;
            }
            
            if (word != s.substr(idx, len)) {
                continue;
            }
            if (dp(s, wordDict, idx + len)) {
                memo[idx] = 1;
                return true;
            }
        }
        memo[idx] = 0;
        return false;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

