/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30203
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        backtrack(digits, 0);
        return res;
    }

private:
    vector<string> key = {
        "","",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> res;
    string track = "";
    void backtrack (string& digits, int idx) { 
        int n = digits.size();
        if (idx == n) {
            res.push_back(track);
            return;
        }
        if (idx > n || idx < 0) {
            return;
        }
        
        char ch = digits[idx];
        int num = ch - '0';
        int len = key[num].size();
        for (int i = 0; i < len; i++) {
            track += key[num][i];
            backtrack(digits, idx + 1);
            track.pop_back();
        }
    }

};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

