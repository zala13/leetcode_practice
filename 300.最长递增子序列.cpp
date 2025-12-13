/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30203
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int cnt = 1;
        int n = nums.size();
        vector<int> head;
        head.push_back(nums[0]);
        cout << nums[0] << ' ';
        for (int i = 1; i < n; i++) {
            int m = head.size();
            for (int j = 0; j < m; j++) {
                if (nums[i] > head[j] ) {
                    if (j == m - 1) {
                        head.push_back(nums[i]);
                        cout << nums[i] << ' ';
                        cnt++;
                    }
                    continue;
                } else {
                    head[j] = nums[i];
                    break;
                }
            }
        }
        cout << '\n';
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

