/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        long long l = 1, r = x;
        while (l < r) {
            // cout << l << " " << r << endl;
            long long mid = (l + r + 1) >> 1;
            if (mid * mid > x) r = mid - 1;
            else l = mid;
        }
        
        return r;
    }
};
// @lc code=end

