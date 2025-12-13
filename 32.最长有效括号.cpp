/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30203
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        
        vector<int> dp(n, 0);  // dp[i]表示以i结尾的最长有效括号长度
        stack<int> stk;        // 存储左括号的索引
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);   // 左括号入栈
                dp[i] = 0;     // 左括号结尾的长度为0
            } else {  // s[i] == ')'
                if (!stk.empty()) {
                    int leftIdx = stk.top();
                    stk.pop();
                    
                    // 计算匹配的括号对长度：基础长度2
                    dp[i] = 2;
                    
                    // 加上左括号前面的有效长度
                    // ()()()
                    if (leftIdx > 0) {
                        dp[i] += dp[leftIdx - 1];
                    }
                    
                    // 关键修复：加上当前匹配区间右边的有效长度
                    // 如果leftIdx右边有连续的有效括号，也要加上
                    // ((()))
                    if (leftIdx + 1 < i) {
                        dp[i] += dp[i - 1];
                    }
                } else {
                    dp[i] = 0;  // 无法匹配的右括号
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};



// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

