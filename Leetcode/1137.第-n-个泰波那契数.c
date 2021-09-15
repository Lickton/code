/*
 * @lc app=leetcode.cn id=1137 lang=c
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start


int tribonacci(int n){
    //  O(n)
    //  39/39 cases passed 0ms(100%) 5.3MB(92.04%)
    if(n == 0 || (n > 0 && n < 3)){
        return n == 0 ? 0 : 1;
    }
    /*
    int trib[40], i;
    trib[0] = 0;
    trib[2] = trib[1] = 1;
    for(i = 3; i <= n; i++)
        trib[i] = trib[i-1] + trib[i-2] + trib[i-3];

    return trib[n];
    }
    */
    int a = 1, b = 1, c = 0, d = 0;//initial value is depend on the loop
    for (int i = 3; i <= n; i++)
    {
        d = c;
        c = b;
        b = a;
        a = b + c + d;
    }
    return a;
}
// @lc code=end
