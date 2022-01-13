/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

    //  3999/3999 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 99.11 % of c submissions (5.6 MB)

int Hashtable(char * s) {
    switch (*s) {
    case 'I': 
        return 1;
        break;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}


int romanToInt(char * s) {
    int res = 0, temp = __INT32_MAX__; // 前一位
    while (*s) {
        int tmp = Hashtable(s);
        if (tmp > temp)
            res = res - 2 * temp + tmp;
        else
            res += tmp;
        temp = tmp;
        s++;
    }
    return res;
}

/*
int romanToInt(char * s){
    int mark = 0;
    int length = strlen(s) - 1;
    int tmp = 0,result = 0;
    while(length >= 0){
        switch(s[length]){
            case 'I':
                tmp = 1;
                break;
            case 'V':
                tmp = 5;
                break;
            case 'X':
                tmp = 10;
                break;
            case 'L':
                tmp = 50;
                break;
            case 'C':
                tmp = 100;
                break;
            case 'D':
                tmp = 500;
                break;
            case 'M':
                tmp = 1000;
                break;
            default:
                tmp = 0;
        }
        if (tmp >=mark){
            result += tmp;
            mark = tmp;
        }else{
            result -= tmp;
        }
        length--;
    }
    return result;
}
*/
// @lc code=end

