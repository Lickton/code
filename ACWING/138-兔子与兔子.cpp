#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000010, P = 13331;

int h[N], p[N], m;
char str[N];

int get(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}

int main()
{
    scanf("%s%d", str+1, &m);
    int len = strlen(str+1);
    
    p[0] = 1;
    for (int i = 1; i <= len; i++) {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}