/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    // 70/70 cases passed (68 ms)
    // Your runtime beats 88.62 % of cpp submissions
    // Your memory usage beats 70.36 % of cpp submissions (45.5 MB)
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
// @lc code=end

