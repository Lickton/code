/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

    // 60/60 cases passed (76 ms)
    // Your runtime beats 86.66 % of c submissions
    // Your memory usage beats 16.9 % of c submissions (11.7 MB)

#define min(m, n) (m < n ? m : n)

int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1;
    int res = 0, MIN;
    while (i < j) {
        MIN = min(height[i], height[j]);
        if (MIN * (j - i) > res)
            res = MIN * (j - i);
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return res;
}
// @lc code=end

