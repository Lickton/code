/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    // 22/22 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 84.06 % of c submissions (5.3 MB)
    int lo = 1, hi = n, mid = lo + (hi - lo) / 2;
    if (n == 1) {
        return 1;
    }
    while (lo <= hi) {
        if (!isBadVersion(mid)) {
            lo = mid + 1;
        } else if (!isBadVersion(mid-1)) {
            return mid;
        } else {
            hi = mid - 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return -1;
}
// @lc code=end

