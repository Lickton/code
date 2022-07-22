#include <iostream>

using namespace std;

const int N = 100010;

typedef long long LL;

LL height[N];
LL posA[N], revA[N];
LL posB[N], revB[N];
int m, n;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);

    for (int i = 1; i < n; i++) {   // from i - 1 -> i
        posA[i] = height[i-1] > height[i] ? height[i-1] - height[i] : 0;
        posB[i] = posB[i-1] + posA[i];
    }

    for (int i = n - 2; i >= 0; i--) {      // from i + 1 -> i
        revA[i] = height[i+1] > height[i] ? height[i+1] - height[i] : 0;
        revB[i] = revB[i+1] + revA[i];
    }

    int s, t;
    while (m--) {
        LL res = 0;
        scanf("%d%d", &s, &t);
        if (s < t) {    
            res = posB[t-1] - posB[s-1];
        } else {
            res = revB[t-1] - revB[s-1];
        }
        printf("%lld\n", res);
    }

    return 0;
}