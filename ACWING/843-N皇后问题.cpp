#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];
int s;

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[i+u] && !udg[n-u+i]) {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[n-u+i] = true;
            dfs(u+1);
            col[i] = dg[u+i] = udg[n-u+i] = false;
            g[u][i] = '.';
        }
    }
}

void dfs_search(int x, int y, int s)
{
    if (y == n)
        y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;
    }

    // 不放皇后
    dfs_search(x, y+1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = true;
        dfs_search(x, y+1, s+1);
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = false;
        g[x][y] = '.';
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    }

    // dfs(0);
    dfs_search(0, 0, 0);

    return 0;
}