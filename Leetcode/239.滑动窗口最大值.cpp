/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int q[nums.size()], hh = 0, tt = -1;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (hh <= tt && i - k + 1 > q[hh]) hh++;
            while (hh <= tt && nums[i] >= nums[q[tt]]) tt--;
            q[++tt] = i;
            if (i >= k - 1) res.push_back(nums[q[hh]]);
        }

        return res;
    }
};
// @lc code=end

