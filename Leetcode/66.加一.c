/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

    // 111/111 cases passed (4 ms)
    // Your runtime beats 50.54 % of c submissions
    // Your memory usage beats 8.24 % of c submissions (6 MB)

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int flag = 1, sign = 1;
    for (int i = 0; i < digitsSize; i++)
        if (digits[i] != 9) {
            flag = 0;
            break;
        }
    *returnSize = digitsSize + flag;
    int * res = (int*)malloc(*returnSize * sizeof(int));

    for (int i = digitsSize - 1; i >= 0; i--) {
        int temp = digits[i] + sign;
        res[i + flag] = temp % 10;
        if (temp == 10)
            sign = 1;
        else
            sign = 0;
    }
    if (flag)
        res[0] = 1;
    return res;
}
// @lc code=end

