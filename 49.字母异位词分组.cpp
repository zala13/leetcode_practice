/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30203
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> valToStr;
        for (int i = 0; i < n; i++) {
            string processed = trans(strs[i]);
            valToStr[processed].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto& str : valToStr) { 
            res.push_back(str.second);
        }
        return res;
    }
private:
    string trans(string& raw) {
        string processed(26, '0');
        for (auto ch : raw) {
            processed[ch - 'a']++;
        }
        return processed;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

