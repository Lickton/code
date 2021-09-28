#include <stdio.h>

int main() {
    long long left, right, temp = 1, res = 0;
    scanf("%lld%lld", &left, &right);
    if (left == right) {
        printf("%lld", left);
        return 0;
    }
    for (res = left | temp; (res | temp) < right; temp <<= 1)
        res = (res | temp);
    printf("%lld", res);
    return 0;
}