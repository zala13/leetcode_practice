/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30203
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        backtrack(root, k);
        return res;
    }

private:
    int res = 0;
    int cur = 0;
    void backtrack(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }

        backtrack(node->left, k);
        cout << node->val << " ";
        cur++;
        if (cur == k) {
            res = node->val;
        }
        backtrack(node->right, k);
    }

};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */

