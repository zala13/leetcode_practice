/*
 * @lc app=leetcode.cn id=49 lang=java
 * @lcpr version=30305
 *
 * [49] 字母异位词分组
 */

// @lc code=start

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap();
        for (int i = 0; i < strs.length; i++) {
            String key = encode(strs[i]);
            map.putIfAbsent(key, new LinkedList<>());
            map.get(key).add(strs[i]);
        }

        List<List<String>> res = new LinkedList<>();
        for (List<String> val : map.values()) {
            res.add(val);
        }
        return res;
    }

    private String encode(String str) {
        char[] encoder = new char[26];
        for (int i = 0; i < str.length(); i++) {
            int n = str.charAt(i) - 'a';
            encoder[n]++;
        }
        return new String(encoder);
    }
}
// @lc code=end



/*
// @lcpr case=start
// ["eat","tea","tan","ate","nat","bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

