/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30203
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) {
            return false;
        }
        if (left != nullptr && right == nullptr) {
            return false;
        }
        if(left == nullptr && right == nullptr) {
            return true;
        }
        if (left->val != right->val) {
            return false;
        }

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

