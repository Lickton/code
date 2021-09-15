/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
int max(int m, int n) {
    return m > n ? m : n;
}
int min(int m, int n) {
    return m < n ? m : n;
}
int maxProfit(int* prices, int pricesSize){
    
    /*  O(n**2) */
    /*
    int best = 0;
    for(int i = 0; i < pricesSize; i++) {
        for(int j = i + 1; j < pricesSize; j++) {
            best = max(best, prices[j] - prices[i]);
        }
    }
    return best;
    */
   
   /*   O(n)    */
   // 211/211 cases passed 104ms(99.68%) 12.7MB(48.36%)
   int maxProfit = 0, minPrice = __INT32_MAX__;
   for(int i = 0; i < pricesSize; i++) {
       minPrice = min(minPrice, prices[i]);
       maxProfit = max(maxProfit, prices[i] - minPrice);
   }
   return maxProfit;
}
// @lc code=end

