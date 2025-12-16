//
////leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//    public boolean isValid(String s) {
//        if (s.length() == 0 || s.length() == 1) {
//            return false;
//        }
//
//        Stack<Character> stk = new Stack<>();
//        for (int i = 0; i < s.length(); i++) {
//            char ch = s.charAt(i);
//            if (ch == ")") {
//                if (stk.isEmpty()) {
//                    return false;
//                }
//                char topChar = stk.peek();
//                stk.pop();
//                if (topChar != "(") {
//                    return false;
//                }
//            } else if (ch == "]") {
//                if (stk.isEmpty()) {
//                    return false;
//                }
//                char topChar = stk.peek();
//                stk.pop();
//                if (topChar != "[") {
//                    return false;
//                }
//
//            } else if (ch == "}") {
//                if (stk.isEmpty()) {
//                    return false;
//                }
//                char topChar = stk.peek();
//                stk.pop();
//                if (topChar != "{") {
//                    return false;
//                }
//
//            } else {
//                stk.push(ch);
//            }
//        }
//
//    }
//}
////leetcode submit region end(Prohibit modification and deletion)

import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public boolean isValid(String s) {
        // 边界条件修正：空字符串有效，长度为奇数直接无效（优化）
        if (s.isEmpty()) {
            return true;
        }
        if (s.length() % 2 != 0) {
            return false;
        }

        // 用Deque替代Stack（更规范）
        Deque<Character> stk = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            // 左括号入栈
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                // 右括号时栈为空，直接无效
                if (stk.isEmpty()) {
                    return false;
                }
                // 弹出栈顶匹配
                char topChar = stk.pop();
                if ((ch == ')' && topChar != '(')
                        || (ch == ']' && topChar != '[')
                        || (ch == '}' && topChar != '{')) {
                    return false;
                }
            }
        }
        // 最终栈为空才有效（无剩余左括号）
        return stk.isEmpty();
    }
}