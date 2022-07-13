#include <iostream>
#include <algorithm>
typedef long long LL;

using namespace std;

const int N = 1e5 + 10;
LL a[N], b[N];
LL n, m, x, i, j;


int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x)
            j--;
        if (a[i] + b[j] == x) {
            cout << i << " " << j;
            break;
        }
    }

    return 0;
}