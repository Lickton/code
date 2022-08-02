#include <iostream>

using namespace std;

const int N = 100010;

int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1;
    
    while (m--) {
        char op[3];
        scanf("%s", op);
        if (*op == 'C') {
            int a, b;
            scanf("%d%d",&a, &b);
            if (find(a) != find(b)) cnt[find(b)] += cnt[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] == '1') {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            int a;
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }
    
    return 0;
}
