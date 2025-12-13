/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30203
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            int ch = s[i];
            switch (ch) {
                case '(':
                    stk.push(ch);
                    break;
                case '[':
                    stk.push(ch);
                    break;
                case '{':
                    stk.push(ch);
                    break;
                case ')':
                    if (!stk.empty() && stk.top() == '(') {
                        stk.pop();
                    } else if (!stk.empty() && stk.top() != '(') {
                        return false;
                    } else if (stk.empty()) {
                        return false;
                    }
                    break;
                case ']':
                    if (!stk.empty() && stk.top() == '[') {
                        stk.pop();
                    } else if (!stk.empty() && stk.top() != '[') {
                        return false;
                    } else if (stk.empty()) {
                        return false;
                    }
                    break;
                case '}':
                    if (!stk.empty() && stk.top() == '{') {
                        stk.pop();
                    } else if (!stk.empty() && stk.top() != '{') {
                        return false;
                    } else if (stk.empty()) {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if (stk.empty()) {
            return true;
        }
        return false;
    }
};
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

