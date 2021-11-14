/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

    //Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 58.66 % of c submissions (5.8 MB)
void inorder(struct TreeNode* root, int* res, int* returnSize) {
    if (!root)
        return;
    inorder(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorder(root->right, res, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int * res = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}
// @lc code=end

