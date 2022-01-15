/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string.h>
#include <math.h>

    // 294/294 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 66.46 % of c submissions (5.6 MB)

void reserve(char * s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

char * addBinary(char * a, char * b) {
    reserve(a);
    reserve(b);

    int lenA = strlen(a), lenB = strlen(b);
    int maxSize = fmax(lenA, lenB), sign = 0, returnSize = 0;

    char *res = (char*)malloc(sizeof(char) * (maxSize + 2));
    for (int i = 0; i < maxSize; i++) {
        int numA = i < lenA ? a[i] - '0' : 0;
        int numB = i < lenB ? b[i] - '0' : 0;
        res[returnSize++] = (numA + numB + sign) % 2 + '0';
        if (numA + numB + sign < 2)
            sign = 0;
        else
            sign = 1;
    }

    if (sign)
        res[returnSize++] = '1';
    res[returnSize] = '\0';
    reserve(res);

    return res;
}
// @lc code=end

