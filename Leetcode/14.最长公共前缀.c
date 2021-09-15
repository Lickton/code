/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    //  longitudinal scan O(mn) m is the average of string 's size & n is strsSize
    //  123/123 cases passed 0ms(100%) 5.9MB(32.83%)
    if(strsSize == 0)
        return NULL;
    int i, j, length = strlen(strs[0]);
    char *lcp = (char *)calloc(201,sizeof(char));
    for(i = 0; i < length; i++) {
        for(j = 1; j < strsSize; j++) {
            if(strs[j][i] != strs[j-1][i])
                return lcp;
        }
        lcp[i] = strs[0][i];
    }
    return lcp;
}
// @lc code=end

