/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30203
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout << left << ' ' << right << '\n';
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (nums[mid] < nums[0]) {
                    right = mid - 1;
                } else {
                    if (target < nums[0]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            } else if (nums[mid] < target) {
                if (nums[mid] >= nums[0]) {
                    left = mid + 1;
                } else {
                    if (target >= nums[0]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

