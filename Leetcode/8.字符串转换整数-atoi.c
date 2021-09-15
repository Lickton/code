/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start


int myAtoi(char * s){
    //  O(n) 
    //  1082/1082 cases passed 0ms(100%) 5.6MB(36.09%)
    int i, ans, sign, num, flag;
    i = sign = ans = num = 0;
    
    for (i = 0; s[i] == ' '; i++);
    
    if (s[i] == '-' || s[i] == '+') {
        s[i] == '-' ? (sign = -1) : (sign = 1);
        i++;
    } else if (s[i] >= '0' && s[i] <= '9') {
        sign = 1;
    } else {
        ans = 0;
        return ans;
    }

    for (; s[i] >= '0' && s[i] <= '9'; i++) {
        num = s[i] - '0';
        if ((ans > __INT32_MAX__ / 10) || ((ans == __INT32_MAX__ / 10) && (num > 7))) {
            return sign > 0 ? __INT32_MAX__ : -__INT32_MAX__ - 1;
        }
        ans = 10 * ans + num;
    }

    return sign > 0 ? ans : -ans;
}
// @lc code=end

