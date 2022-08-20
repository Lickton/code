/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    static const int N = 20;
    char g[N][N];
    bool col[N], dg[N], udg[N];
    
    void dfs(vector<vector<string>> &res, int u, int n) {
        if (u == n) {
            vector<string> tmp2;
            for (int i = 0; i < n; i++) {
                string tmp = "";
                for (int j = 0; j < n; j++)
                    tmp.push_back(g[i][j]);
                tmp2.push_back(tmp);
            }
            res.push_back(tmp2);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u+i] && !udg[n-u+i]) {
                g[u][i] = 'Q';
                col[i] = dg[u+i] = udg[n-u+i] = true;
                dfs(res, u+1, n);
                g[u][i] = '.';
                col[i] = dg[u+i] = udg[n-u+i] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = '.';
        dfs(res, 0, n);
        return res;
    }
};
// @lc code=end

