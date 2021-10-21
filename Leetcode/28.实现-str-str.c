/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/*
    80/80 cases passed (0 ms)
    Your runtime beats 100 % of c submissions
    Your memory usage beats 44.1 % of c submissions (6.1 MB)
*/
void BuildNext(char * neddle, int lenN, int * next) {
    int i = 1, j = 0, temp;
    while (i < lenN) {
        if (neddle[i] == neddle[j])
            next[i++] = ++j;
        else if (j != 0)
            j = next[j-1];
        else
            next[i++] = 0;
    }
}

int strStr(char * haystack, char * needle){
    int lenH = (int)strlen(haystack), lenN = (int)strlen(needle);
    if (lenN == 0)
        return 0;
    int next[lenN], i = 0, j = 0;
    memset(next, 0, (unsigned long)lenN);
    BuildNext(needle, lenN, next);
    while (i < lenH) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else if (j != 0)
            j = next[j-1];
        else
            i++;
        if (j == lenN)
            return i - j;
    }
    return -1;
}
// @lc code=end

