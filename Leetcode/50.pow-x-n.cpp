/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (!x || x == 1) return x;
        if (!n)  return 1.0;
        double res = (n > 0 ? x : 1/x), mult;
        mult = res;
        long long cnt = (n > 0 ? n : -(long long)n);
        long long i;
        
        for (i = 1; i * 2 <= cnt;) {
            if (!res) break;
            i *= 2;
            res *= res;
        }
        
        while (i < cnt) {
            if (!res) break;
            res *= mult;
            i++;
        }
        
        return res;
    }
};
// @lc code=end

