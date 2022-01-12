/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

// @lc code=start

    //  31/31 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 82.01 % of c submissions (5.3 MB)

int fib_iter(int a, int b, int p, int q, int count) {
    if (count == 0)
        return b;
    if (count % 2 == 0)
        return fib_iter(a, b, (q*q + p*p), (2*p*q + q*q), count / 2);
    else
        return fib_iter(b*q + a*q + a*p, b*p + a*q, p, q, count - 1);
}

int fib(int n){
    //  O(n) 
    //  31/31 cases passed 0ms(100%) 5.5MB(35.75%)
    /*
    int f = 0, g = 1;
    if(n == 0) {
        return 0;
    }
    while(--n) {
        g = g + f;
        f = g - f;
    }

    return g;
    */
    return fib_iter(1, 0, 0, 1, n);
}
// @lc code=end

