#include <stdio.h>

int hailstone(int n);
void swap(int * m, int * n);
int max(int m, int n);

int main()
{
    int i, j, k;
    int temp = 0, flag = 0;
    while(scanf("%d%d", &i, &j) != EOF) {
        temp = flag = 0;
        if (i > j) {
            flag = 1;
            swap(&i, &j);
        }
        for(k = i; k <= j; k++) {
            temp = max(temp, hailstone(k));
        }
        if (flag == 1)
            swap(&i, &j);
        printf("%d %d %d\n", i, j, temp);
    }

    return 0;
}

int hailstone(int n)
{
    int length = 1;
    while (n > 1) {
        (n & 1) ? (n = 3 * n + 1) : (n /= 2);
        ++length;
    }

    return length;
}

void swap(int * m, int * n)
{
    int temp = 0;
    temp = *m;
    *m = *n;
    *n = temp;
}

int max(int m, int n)
{
    if (m >= n)
        return m;
    else
        return n;
}