/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30203
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, len = nums.size();
        return arrToBST(nums, start, len);
    }

private:
    TreeNode* arrToBST(vector<int>& nums, int start, int len) {
        if (start < 0 || start >= nums.size() || len <= 0 || len > nums.size()) {
            return nullptr;
        }
        int idx = (start + (start + len - 1)) / 2;
        int val = nums[idx];
        TreeNode* node = new TreeNode(val);
        int left_len = idx - start;
        node->left = arrToBST(nums, start, left_len);
        int right_len = len - left_len - 1;
        node->right = arrToBST(nums, idx + 1, right_len);
        return node;        
    }

};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

