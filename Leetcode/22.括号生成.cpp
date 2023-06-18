/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    int cnt;
    string path;
    vector<string> res;
    
    void dfs(int x, int y) {
        // cout << x << " " << y << " " << path << endl;
        if (y == cnt) {
            res.push_back(path);
        } else if (x == cnt) {
            path.push_back(')');
            dfs(x, y+1);
            path.pop_back();
        } else if (x > y) {
            path.push_back('(');
            dfs(x+1, y);
            path.pop_back();
            path.push_back(')');
            dfs(x, y+1);
            path.pop_back();
        } else {
            path.push_back('(');
            dfs(x+1, y);
            path.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        cnt = n;
        path.push_back('(');
        
        dfs(1, 0);
        
        return res;
    }
};
// @lc code=end

