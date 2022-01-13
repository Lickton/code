/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 */

// @lc code=start

#include <string.h>

    // 95/95 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 23.98 % of c submissions (5.8 MB)

int longestPalindrome(char * s){
    int hash[58] = {0};
    int len = strlen(s);
    int res = 0, flag = 1;

    for (int i = 0; i < len; i++)
        hash[s[i] - 'A']++;

    for (int i = 0; i < 58; i++) {
        if (hash[i] == 0)
            continue;
        else if (hash[i] % 2 == 0)
            res += hash[i];
        else if (!flag) {
            res += hash[i] - 1;
        } else {
            res += hash[i];
            flag = 0;
        }
    }
    return res;
}
// @lc code=end

