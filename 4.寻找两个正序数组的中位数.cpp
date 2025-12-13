/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30203
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        for (int i = 0, j = 0; i < m, j < n; ) {
            if (nums1[i] > nums2[j]) {
                if (i)
                i++;
            } else (nums1[i] < nums2[j]) {
                j++;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

