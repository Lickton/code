/*
 * @lc app=leetcode.cn id=1768 lang=c
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
char * mergeAlternately(char * word1, char * word2){
    //  108/108 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 36.28 % of c submissions (5.8 MB)
    int len1 = strlen(word1), len2 = strlen(word2);
    int pos = 0, i = 0, j = 0;
    char * res = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    while (i < len1 && j < len2) {
        res[pos++] = word1[i++];
        res[pos++] = word2[j++];
    }
    while (i < len1) {
        res[pos++] = word1[i++];
    }
    while (j < len2) {
        res[pos++] = word2[j++];
    }
    res[pos] = '\0';
    return res;
}

    //  执行消耗内存为 5644 kb 的范例
    /*
    if (NULL == word1) return word2;
    if (NULL == word2) return word1;
    static char str[201], *p;
    memset(str, 0x00, 201);
    p = str;
    while (*word1 && *word2) {
        //printf("word: %c %c\n", *word1, *word2);
        *p++ = *word1++;
        *p++ = *word2++;
        //printf("str: %s\n", str);
    }
    while (*word1) *p++ = *word1++;
    while (*word2) *p++ = *word2++;
    //printf("str: %s\n", str);
    return str;
    */
// @lc code=end

