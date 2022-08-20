/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                res ++;
        }
        return res;
    }
};
// @lc code=end

