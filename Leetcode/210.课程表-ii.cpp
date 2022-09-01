/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> g;
        int d[2010] = {0}, q[2010] = {0}, hh = 0, tt = -1;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }
        
        for (int i = 0; i < numCourses; i++)
            if (!d[i]) q[++tt] = i;
        
        while (hh <= tt) {
            int t = q[hh++];
            res.push_back(t);
            for (int i = 0; i < g[t].size(); i++) {
                int j = g[t][i];
                if (--d[j] == 0) q[++tt] = j;
            }
        }
        
        return res.size() == numCourses ? res : vector<int> {};
    }
};
// @lc code=end

