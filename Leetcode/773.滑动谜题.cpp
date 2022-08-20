/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int bfs(string start) {
        unordered_map<string, int> d;
        string end = "123450";
        queue<string> q;
        
        q.push(start);
        d[start] = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        while (q.size()) {
            auto t = q.front(); q.pop();
            int distance = d[t];
            if (t == end) return d[t];
            int k = t.find('0');
            int x = k / 3, y = k % 3;
            
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < 2 && b >= 0 && b < 3) {
                    swap(t[k], t[a*3 + b]);
                    
                    if (!d.count(t)) {
                        d[t] = distance + 1;
                        q.push(t);
                    }
                    
                    swap(t[k], t[a*3+b]);
                }
            }
        }
        return -1;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                start += board[i][j] + '0';
        return bfs(start);
    }
};
// @lc code=end

