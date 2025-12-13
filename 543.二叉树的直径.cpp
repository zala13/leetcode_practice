/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30203
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        backtrack(root);
        return res;
    }

private:
    int res = 0;
    int backtrack(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left = backtrack(node->left);
        int right = backtrack(node->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

