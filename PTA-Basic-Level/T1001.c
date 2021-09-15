#include <stdio.h>

int hailstone (int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", hailstone(n));

    return 0;
}

int hailstone (int n)
{
    int length = 0;
    
    while (n > 1) {
        if(n & 1)
            n = 3 * n + 1;
        else {
            n /= 2;
            ++length;
        }
    }

    return length;
}