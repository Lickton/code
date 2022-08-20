/*
 * @lc app=leetcode.cn id=101 lang=cpp
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
    bool cmp(TreeNode* le, TreeNode* ri) {
        if (le == NULL && ri == NULL) return true;
        if (le == NULL || ri == NULL) return false;
        if (le->val != ri->val) return false;
        return cmp(le->left, ri->right) && cmp(le->right, ri->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return cmp(root->left, root->right);
    }
};
// @lc code=end

