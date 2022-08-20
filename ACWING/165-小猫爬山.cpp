#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 20;

int n, w;
int res = 0x3f3f3f3f;
int we[N], sum[N];

void dfs(int u, int s)
{
    if (s >= res) return;
    
    if (u == n) {
        res = s;
        return;
    }

    for (int i = 0; i < s; i++) {
        if (sum[i] + we[u] <= w) {
            sum[i] += we[u];
            dfs(u+1, s);
            sum[i] -= we[u];
        }
    }

    sum[s] = we[u];
    dfs(u+1, s+1);
    sum[s] = 0;
}

int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        scanf("%d", &we[i]);
    
    sort(we, we+n);
    reverse(we, we+n);

    dfs(0, 0);
    
    cout << res << endl;
    
    return 0;
}