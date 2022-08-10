#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], n, k;

int quick_select(int q[], int l, int r, int k) {
    if (l == r)
        return q[l];
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    int sl = j - l + 1;
    if (k <= sl)
        return quick_select(q, l, j, k);
    else
        return quick_select(q, j + 1, r, k - sl);
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("%d", quick_select(q, 0, n - 1, k));

    return 0;
}