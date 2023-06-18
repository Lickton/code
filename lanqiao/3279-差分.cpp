#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int a[N], b[N];

int main()
{
    int T;
    cin >> T;
    
    while (T--) {
        cin >> n;
        memset(b, 0, (n+1) * 4);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int l = max(i-a[i]+1, 1), r = i;
            b[l]++, b[r+1]--;
        }
        
        for (int i = 1; i <= n; i++) {
            b[i] += b[i-1];
        }
        
        for (int i = 1; i <= n; i++) {
            printf("%d ", !!b[i]);
        }
        puts("");
    }
    
    return 0;
}