#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertion_sort(int arr[], int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while((j >= 0) && (arr[j] > key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void binsert_sort(int arr[], int len) {
    int i, j, low, high = 0, mid;
    int temp = 0;
    for (i = 1; i < len; i++) {
        low = 0;
        high = i-1;
        temp = arr[i];
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] > temp)
                high = mid-1;
            else
                low = mid + 1;
        }
        for(j = i; j > low; j--)
            arr[j] = arr[j-1];
        arr[low] = temp;
    }
}

void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j-= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

void bubble_sort(int arr[], int len) {
    int i, j, temp, exchanged = 1;
    for (i = 0; exchanged && i < len - 1; i++) {
        exchanged = 0;
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchanged = 1;
            }
        }
    }
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

void selection_sort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void merge_sort(int arr[], const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

int main () {
    int arr[10000];
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    time_t c_start, c_end;
    c_start = clock();// 单位为ms
    insertion_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("直接插入排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    binsert_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("折半插入排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    shell_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("希尔排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    bubble_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("冒泡排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    quick_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("快速排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    selection_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("简单选择排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    srand((unsigned)time(&t));
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    c_start = clock();// 单位为ms
    merge_sort(arr, 10000);
    c_end   = clock();
    //!<difftime（time_t, time_t）返回两个time_t变量间的时间间隔，即时间差
    printf("归并排序方法消耗 %f ms \n",difftime(c_end,c_start)); 

    return 0;
}