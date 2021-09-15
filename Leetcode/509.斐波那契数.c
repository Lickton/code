/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

// @lc code=start


int fib(int n){
    //  O(n) 
    //  31/31 cases passed 0ms(100%) 5.5MB(35.75%)
    int f = 0, g = 1;
    if(n == 0) {
        return 0;
    }
    while(--n) {
        g = g + f;
        f = g - f;
    }

    return g;
}
// @lc code=end

