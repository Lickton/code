/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
 */

// @lc code=start

#include <stdio.h>

    //Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
    //  77/77 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 93.5 % of c submissions (5.7 MB)
    if (root == NULL)
        return root;
    struct TreeNode * _;
    _ = root->left;
    root->left = root->right;
    root->right = _;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}
// @lc code=end

