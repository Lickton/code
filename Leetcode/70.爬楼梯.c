/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){
    //  O(n)
    //  45/45 cases passed 0ms(100%) 5.5MB(36.74%)
    int g = 0, f = 1;
    while (n-- >= 0) {
        g = g + f;
        f = g - f;
    }
    return g;
}
// @lc code=end

