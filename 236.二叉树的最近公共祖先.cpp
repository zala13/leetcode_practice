/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30203
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        target = root;
        find(root, p, q);
        return target;
    }

private:
    TreeNode* target;
    int find(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) {
            return 0;
        }
        int left = find(node->left, p, q);
        int right = find(node->right, p, q);
        int mid = 0;
        if (node == p || node == q) {
            mid = 1;
        }
        if (mid + left + right >= 2) {
            target = node;
            return 0;
        }
        if (mid + left + right == 1) {
            return 1;
        }
        return 0;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

