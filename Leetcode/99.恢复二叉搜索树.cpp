/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void help(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;
        help(root->left, res);
        res.push_back(root->val);
        help(root->right, res);
    }
    
    void dfs(TreeNode *root, int count, int x, int y) {
        if (root == NULL) return;
        if (root->val == x || root->val == y) {
            root->val = root->val == x ? y : x;
            if (--count == 0) return;
        }
        dfs(root->left, count, x, y);
        dfs(root->right, count, x, y);
    }
    
    void recoverTree(TreeNode* root) {
        int x = -1, y = -1;
        vector<int> res;
        help(root, res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] < res[i-1]) {
                y = i;
                if (x == -1) x = i-1;
            }
        }
        dfs(root, 2, res[x], res[y]);
    }
};
// @lc code=end

