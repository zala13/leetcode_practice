/*
 * @lc app=leetcode.cn id=17 lang=java
 * @lcpr version=30305
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    String[] keyToChar = new String[] {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if (digits == null) {
            return null;
        }
        
        trackback(digits, 0, new StringBuilder());
        return res;
    }

    private void trackback(String digits, int index, StringBuilder path) {
        if (index == digits.length()) {
            res.add(path.toString());
            return;
        }

        String choice = keyToChar[digits.charAt(index) - '0'];
        for (int j = 0; j < choice.length(); j++) {
            path.append(choice.charAt(j));
            trackback(digits, index + 1, path);
            path.deleteCharAt(path.length() - 1);
        }
        
    }
}
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

