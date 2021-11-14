/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    // 1032/1032 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 59.6 % of c submissions (5.5 MB)
    int ans = 0, flag = 0;
    if (x % 10 == x)
        return x;
    if (x < 0)
        flag = 1;
    while (x) {
        if ((flag && ans < -__INT32_MAX__ / 10) || (!flag && ans > (__INT32_MAX__ - 1) / 10))
            return 0;
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
// @lc code=end

