/*
 * @lc app=leetcode.cn id=191 lang=c
 *
 * [191] 位1的个数
 */

// @lc code=start
int hammingWeight(uint32_t n) {
    // O(n)
    // 601/601 cases passed 0ms(100%) 5.3MB(69.14%)
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    } 

    return count;
}
// @lc code=end

