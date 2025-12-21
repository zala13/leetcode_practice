/*
 * @lc app=leetcode.cn id=39 lang=java
 * @lcpr version=30305
 *
 * [39] 组合总和
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        traceback(candidates, target, 0, 0);
        return res;
    }

    List<List<Integer>> res = new ArrayList<>();
    List<Integer> track = new ArrayList<Integer>();
    private void traceback(int[] candidates, int target, int index, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.add(new ArrayList<>(track));
            return;
        }
        if (index >= candidates.length) {
            return;
        }
        for (int i = index; i < candidates.length; i++) {
            track.add(candidates[i]);
            traceback(candidates, target, i, sum + candidates[i]);
            track.remove(track.size() - 1);
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

