/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30203
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }

    bool isValid(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) {
            return true;
        }
        if (min != nullptr && node->val <= min->val) {
            return false;
        }
        if (max != nullptr && node->val >= max->val) {
            return false;
        }
        return isValid(node->left, min, node)
                && isValid(node->right, node, max);

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

