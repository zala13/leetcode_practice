/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30203
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int n = preorder.size();
        return build(preorder, 0,
                     inorder, 0,
                     n);
    }

private:
    TreeNode* build(vector<int>& preorder, int pStart,
                    vector<int>& inorder, int iStart,
                    int len) 
    {
        int n = preorder.size();
        if (pStart < 0 || iStart < 0 || len <= 0 || pStart >= n || iStart >= n || len > n) {
            return nullptr;
        }

        int val = preorder[pStart];
        TreeNode* node = new TreeNode(val);

        int iIdx;
        for (int i = 0; i < preorder.size(); i++) {
            if (val == inorder[i]) {
                iIdx = i;
            }
        }

        int left_len = iIdx - iStart;
        node->left = build(preorder, pStart + 1,
                            inorder, iStart,
                            left_len);
        int right_len = iStart + len - iIdx - 1;
        node->right = build(preorder, pStart + 1 + left_len,
                            inorder, iIdx + 1,
                            right_len);
        return node;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

