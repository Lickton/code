/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 旋转数组
 */

// @lc code=start
/*
int gcd(int m, int n) {
    return n ? gcd(n, m % n) : m;
}
*/


void swap(int * m, int * n) {
    int temp = *m;
    *m = *n;
    *n = temp;
}

void reverse(int * A, int start, int end) {
    while (start < end)
        swap(&A[start++], &A[end--]);
}

void rotate(int* nums, int numsSize, int k){
    //  Reverse O(n) O(1) Ottoman
    //  37/37 cases passed 100ms(97.18%) 21.5MB(90.87%)
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
    

    //  Ring replacement O(n) O(1) Ottoman
    // 37/37 cases passed 108ms(84.81%) 21.7MB(44%)
    /*
    k = k % numsSize;
    for (int i = 0; i < gcd(numsSize, k); i++) {
        int current = (i + k) % numsSize;
        do {
            swap(&nums[i], &nums[current]);
            current = (current + k) % numsSize;
        } while (i != current);
    }
    */
    
    // O(n) O(n) Ottoman
    // 37/37 cases passed 112ms(76.19%) 21.8MB(25.5%)
    /*
    int newArr[numsSize];
    for (int i = 0; i < numsSize; i++) {
        newArr[(i+k)%numsSize] = nums[i];
    }    
    for (int i = 0; i < numsSize; i++)
        nums[i] = newArr[i];
    */

    //  Recursion  (Decrease-and-conquer) O(n) O(1) Ottoman
    //  Time Limit Exceeded 36/37 cases passed(N/A)
    /*
    if (k == 1) {
        int temp = nums[numsSize-1];
        for (int i = numsSize - 1; i > 0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    } else {
    while (k--)
        rotate(nums, numsSize, 1);
    }
    */
}
// @lc code=end

