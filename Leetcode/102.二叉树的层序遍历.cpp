/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q, p;
        q.push(root);
        while (q.size()) {
            vector<int> tmp;
            while (q.size()) {
                auto t = q.front(); q.pop(); 
                if (t->left) p.push(t->left);
                if (t->right) p.push(t->right);
                tmp.push_back(t->val);
            }
            res.push_back(tmp);
            while (p.size()) {
                auto t = p.front(); p.pop(); q.push(t);
            }
        }
        return res;
    }
};
// @lc code=end

