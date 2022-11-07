#include <iostream>
#include <algorithm>

using namespace std;

void divide(int n)
{
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (n > 1) printf("%d %d\n", n, 1);
    puts("");
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int a;
        scanf("%d", &a);
        divide(a);
    }
    
    return 0;
}
