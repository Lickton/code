/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> b(nums.size()+1);
        int _min = 10010, dp;
        b[0] = 0, dp = -10010;
        for (int i = 1; i <= nums.size(); i++) {
            b[i] = b[i-1] + nums[i-1];
            _min = min(_min, b[i-1]);
            dp = max(b[i] - _min, dp);
        }
        return dp;
    }
};
// @lc code=end

