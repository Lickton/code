/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    //  Double pointer O(n)
    //  362/362 cases passed 20ms(63.71%) 7.3MB(94.66%)
    int i, j, ans = 1;
    if (numsSize == 0) 
        return 0;
    for(i = 0, j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
            ans++;
        }
    }

    return ans;
}
// @lc code=end

