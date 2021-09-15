/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //  O(n**2)
    //  55/55 cases passed 68ms (77.07%) 6.1MB(94.26%)
    int * res = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        int newTarget = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (newTarget == nums[j]) {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }

    return 0;
}
// @lc code=end

