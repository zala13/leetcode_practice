/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30203
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        auto cmp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq;

        for (int i = 0; i < n; i++) {
            if (pq.size() == k) {
                int tmp = pq.top();
                if (nums[i] > tmp) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            } else {
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,5,6,4]\n 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

;