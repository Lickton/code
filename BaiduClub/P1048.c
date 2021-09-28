#include <stdio.h>

int main() {
    long long n, res = 1;
    scanf("%lld", &n);
    if (n == 1) {
        printf("%lld", n);
        return 0;
    }
    while ((res << 1) + 1 < n) {
        res = (res << 1) + 1;
    }
    printf("%lld", res);

    return 0;
}