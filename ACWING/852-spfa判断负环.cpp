#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 10010;

int dist[N], cnt[N];
int h[N], ne[N], e[N], w[N], idx;
bool st[N];

int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }
    
    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    
    while (m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    
    if (spfa()) puts("Yes");
    else puts("No");
    
    return 0;
} 