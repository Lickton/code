/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int, vector<int>> g;
        int d[100010] = {0}, cnt = 0;
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }
        
        for (int i = 0; i < n; i++)
            if (!d[i])  q.push(i), cnt++;
        
        while (q.size()) {
            int t = q.front(); q.pop();
            for (int i = 0; i < g[t].size(); i++)
                if (--d[g[t][i]] == 0) q.push(g[t][i]), cnt++;
        }
        return cnt == n;
    }
};
// @lc code=end

