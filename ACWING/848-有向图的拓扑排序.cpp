#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = 2 * N;

int n, m;
int e[N], ne[N], h[M], idx;
int q[N], tt, hh;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[++tt] = i;
    
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n-1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (topsort()) {
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
        puts("");
    } else cout << -1 << endl;

    return 0;
}