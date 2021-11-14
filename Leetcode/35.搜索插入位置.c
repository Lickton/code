/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    // 64/64 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 79.72 % of c submissions (5.8 MB)
    int left = 0, right = numsSize - 1, middle = (left + right) / 2;
    if(target < nums[0])
        return 0;
    if (target > nums[numsSize-1])
        return numsSize;
    while (left <= right) {
        if (nums[middle] == target)
            return middle;
        else if (nums[middle] < target)
            left = middle + 1;
        else if (nums[middle] > target)
            right = middle - 1;
        middle = (left + right) / 2;
    }
    return left;
}
// @lc code=end

