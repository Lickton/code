/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start

#define max(m, n) m > n ? m : n

int rob(int* nums, int numsSize){
    //  68/68 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 32.63 % of c submissions (5.8 MB)
    int dp[numsSize];
    if (numsSize == 1) {
        return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = max((nums[i] + dp[i-2]), dp[i-1]);
    }

    return dp[numsSize-1];
}
// @lc code=end

 