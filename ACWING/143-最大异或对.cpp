#include <iostream>

using namespace std;

const int N = 100010, M = 31 * N;

int son[M][2], idx;

void insert(int x) 
{
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (son[p][!u]) {
            p = son[p][!u];
            res += (1 << i);
        }
        else p = son[p][u];
    }
    
    return res;
}

int main()
{
    int n, x, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
        res = max(res, query(x));
    }
    
    printf("%d\n",res);
}
