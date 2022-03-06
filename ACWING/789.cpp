#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, k, q[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--) {
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (q[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] != k)
            printf("-1 -1\n");
        else {
            printf("%d ", l);
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            printf("%d\n", r);
        }
    }

    return 0;
}