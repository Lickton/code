#include <stdio.h>
#include <stdlib.h>

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
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

int main() {
    int * nums;
    int total, k, i = 0;
    scanf("%d%d", &total, &k);
    nums = (int *)malloc(sizeof(int) * total);
    for (i = 0; i < total; i++)
        scanf("%d", nums + i);
    rotate(nums, total, k);
    for (i = 0; i < total - 1; i++)
        printf("%d ", nums[i]);
    printf("%d", nums[total-1]);

    return 0;
}