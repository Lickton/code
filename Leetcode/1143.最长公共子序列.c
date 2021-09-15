/*
 * @lc app=leetcode.cn id=1143 lang=c
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string.h>
int max(int m, int n) {
    return m > n ? m : n;
}
int longestCommonSubsequence(char * text1, char * text2){
    //  O(n ** 2)
    //  44/44 cases passed 12ms(78%) 9.7MB(73.69%)
    int m = strlen(text1), n = strlen(text2);
    int lcs[m+1][n+1];
    for(int i = 0; i <= m; i++)
        lcs[i][0] = 0;
    for(int j = 0; j <= n; j++)
        lcs[0][j] = 0; 
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}
// @lc code=end

