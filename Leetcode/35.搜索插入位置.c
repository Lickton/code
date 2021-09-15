/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    int lo = 0, hi = numsSize - 1, mid = lo + (hi - lo) / 2;
    if (nums[0] > target) {
        return 0;
    } else if (nums[numsSize - 1] < target) {
        return numsSize;
    }
    while (lo <= hi) {
        if (lo == hi) {
            mid = lo;
            break;
        }
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return mid;
}
// @lc code=end

