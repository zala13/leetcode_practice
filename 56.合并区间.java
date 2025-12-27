/*
 * @lc app=leetcode.cn id=56 lang=java
 * @lcpr version=30305
 *
 * [56] 合并区间
 */

// @lc code=start

import java.util.Arrays;
import java.util.LinkedList;

class Solution {
    public int[][] merge(int[][] intervals) {
        LinkedList<int[]> res = new LinkedList<>();
        Arrays.sort(intervals, (a, b) -> {
            return a[0] - b[0];
        });
        res.add(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            int[] curr = intervals[i];
            int[] old = res.getLast();
            if (old[1] >= intervals[i][0]) {
                old[1] = Math.max(old[1], curr[1]);
            } else {
                res.add(curr);
            }
        }
        return res.toArray(new int[0][0]);
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */

