/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30203
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for (auto ch : s) {
            if (ch == ']') {
                string tmp = "";
                while (!stk.empty() && stk.top() <= 'z' && stk.top() >= 'a') {
                    tmp += stk.top();
                    stk.pop();
                }
                reverse(tmp.begin(), tmp.end()); // 因为栈是反的

                
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }

                string numstr;
                while (!stk.empty() && stk.top() <= '9' && stk.top() >= '0') {
                    numstr += stk.top();
                    stk.pop();
                }
                reverse(numstr.begin(), numstr.end());

                int k = numstr.empty() ? 1 : stoi(numstr);

                string repeated = "";
                for ( int i = 0; i < k; i++) {
                    repeated += tmp;
                }
                for (auto c : repeated) {
                    stk.push(c);
                }
            } else {
                stk.push(ch);
            }
            
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

