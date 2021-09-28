#include <stdio.h>

int OneinBin(long long n) {
    int count = 0;
    while (n > 0 ) {
        if (n % 2 == 1)
            count++;
        n >>= 1;
    }
    return count;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d", OneinBin(n));
    return 0;
}