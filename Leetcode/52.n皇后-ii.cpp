/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    static const int N = 20;
    char g[N][N];
    bool col[N], dg[N], udg[N];
    
    void dfs(int &res, int u, int n) {
        if (u == n) {
            res++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[i+u] && !udg[n-u+i]) {
                g[u][i] = 'Q';
                col[i] = dg[u+i] = udg[n-u+i] = true;
                dfs(res, u+1, n);
                g[u][i] = '.';
                col[i] = dg[u+i] = udg[n-u+i] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = '.';
        dfs(res, 0, n);
        return res;
    }
};
// @lc code=end

