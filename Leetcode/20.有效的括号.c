/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>
bool isValid(char * s){
    //  91/91 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 95.73 % of c submissions (5.4 MB)
    int len = strlen(s), pre = 0, cur = 1;
    char stack[len];
    stack[0] = *s;
    while (*++s) {
        if (pre == -1) {
            pre++;
            stack[cur] = *s;
            cur++;
        } else if (stack[pre] != (*s) - 1 && stack[pre] != (*s) - 2) {
            stack[cur++] = *s;
            pre++;
        } else {
            cur--;
            pre--;
        }
    }
    if (cur == 0)
        return true;
    else
        return false;

    //  Example of 5396 kb
    /*
    int n = strlen(s);
    if(n % 2 == 1)
        return false;
    int i = 0,top = 0;
    char temp[n+1];
    while(s[i] != '\0'){
        if(s[i] == '(' ||s[i] == '[' ||s[i] == '{' ){
            temp[top] = s[i];
            top++;
        }
        else if(s[i] == ')'){
            if(top == 0 || temp[top - 1] != '(')
                return false;
            else 
                top = top - 1;
        }
        else if(s[i] == ']'){
            if(top == 0 || temp[top - 1] != '[')
                return false;
            else 
                top = top - 1;
        }
        else if(s[i] == '}'){
            if(top == 0 || temp[top - 1] != '{')
                return false;
            else 
                top = top - 1;
        }
        i++;
    }
    return top == 0;
    */
}
// @lc code=end

