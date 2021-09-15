/*
 * @lc app=leetcode.cn id=1894 lang=c
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start


int chalkReplacer(int* chalk, int chalkSize, int k){
    //  72/72 cases passed (112 ms)
    //  Your runtime beats 95.03 % of c submissions
    //  Your memory usage beats 88.4 % of c submissions (13 MB)
    int i = 0, pos = 0;
    long long cost = 0; // Considering the int type overflow
    while (pos < chalkSize) {
        cost += chalk[pos++];
    }
    k %= cost;
    if ( k == 0) {
        return 0;
    } else {
        while ((k -= chalk[i]) >= 0) {
            i++;
        }
        return i;
    }
    //  执行用时为 100 ms 的范例
    /*
    long sum = 0;
    int tmp = k;

    for (int i = 0; i < chalkSize; i++) {
        sum += chalk[i];
    }

    if (k >= sum) {
        tmp = k % sum;
    }

    for (int i = 0; i < chalkSize; i++) {
        if (chalk[i] > tmp) {
            return i;
        }
    tmp -= chalk[i];
    }
    */

}
// @lc code=end

