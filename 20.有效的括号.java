/*
 * @lc app=leetcode.cn id=20 lang=java
 * @lcpr version=30305
 *
 * [20] 有效的括号
 */

// @lc code=start

import java.util.List;

class Solution {
    public boolean isValid(String s) {
        List<Character> stk = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stk.add(c);
            } else {
                if (stk.isEmpty()) {
                    return false;
                }
                char top = stk.get(stk.size() - 1);
                if ((top == '(' && c != ')') || 
                    (top == '[' && c != ']') ||
                    (top == '{' && c != '}')) {
                    return false;
                } else {
                    stk.remove(stk.size() - 1);
                }
            }
        }
        return stk.isEmpty();
    }
}
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

