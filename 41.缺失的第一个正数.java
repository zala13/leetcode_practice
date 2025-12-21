/*
 * @lc app=leetcode.cn id=41 lang=java
 * @lcpr version=30305
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
    public int firstMissingPositive(int[] nums) {
        int res = 1;
        // for (int i = 0; i < nums.length; i++) {
        //     if (res < nums[i]) {
        //         continue;
        //     } else if (res == nums[i]){
        //         res++;
        //     }
        // }
        // return res;

        for (int i = 0; i < nums.length; i++) {
            while (nums[i] < nums.length && nums[i] >= 0 && nums[i] != i) {
                // System.out.println(i + " " + nums[i] + " " + nums[nums[i]]);
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
            if (nums[i] != i && i != 0) {
                res = i;
                break;
            }
            if (i == nums.length - 1) {
                res = nums[i] + 1;
            }
        }
        return res;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

