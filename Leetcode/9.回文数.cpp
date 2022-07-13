/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
    // 11510/11510 cases passed (4 ms)
    // Your runtime beats 94.86 % of cpp submissions
    // Your memory usage beats 89.63 % of cpp submissions (5.7 MB)
        if (x < 0)
            return false;
        int temp = x, weight = 1, divisor = 1;
        while (temp >= 10) {
            temp /= 10;
            weight++;
            divisor *= 10;
        }
        while (weight > 1) {
            if (x % 10 != x / divisor)
                return false;
            x %= divisor;
            divisor /= 100;
            weight -= 2;
            x /= 10;
        }

        return true;
    }
};
// @lc code=end

