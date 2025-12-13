/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30203
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = -1;
        while (!q.empty()) {
            int sz  = q.size();
            depth++;
            res.push_back(-1);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) {
                    res[depth] = node->val;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

