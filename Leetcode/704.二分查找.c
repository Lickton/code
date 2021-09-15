/*
 * @lc app=leetcode.cn id=704 lang=c
 *
 * [704] 二分查找
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
    // 46/46 cases passed (28 ms)
    // Your runtime beats 97.49 % of c submissions
    // Your memory usage beats 84.46 % of c submissions (7.1 MB)
    int hi = numsSize - 1, lo = 0, mid = lo + (hi - lo) / 2;
    while (lo <= hi) {
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return -1;

    // 执行用时为 16 ms 的范例
    /*
    if ((nums == NULL) || (numsSize <= 0)) {
        return -1;
    }

    if ((target < nums[0]) || (target > nums[numsSize - 1])) {
        return -1;
    }

    int start = 0;
    int end = numsSize - 1;
    int findFlg = -1;
    while ((end > (start + 1)) && (findFlg == -1)) {
        int mid = (start + end + 1) / 2;
        //printf("start : %d , end : %d mid : %d \n", start, end, mid);

        (nums[mid] == target) ? findFlg = mid :
        ((nums[mid] > target) ? (end = mid) : (start = mid));
    }

    (nums[start] == target) ? findFlg = start : NULL;
    (nums[end] == target) ? findFlg = end : NULL;

    return findFlg;
    */
}
// @lc code=end

