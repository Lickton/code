#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2 * N;

int n, m;
int e[N], ne[N], idx, h[M];
int q[M], hh, tt;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int u)
{
    memset(d, -1, sizeof(d));
    d[1] = 0;
    q[tt++] = u;
    
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                q[tt++] = j;
                d[j] = d[t] + 1;
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs(1) << endl;

    return 0;
}