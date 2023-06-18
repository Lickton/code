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
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        int l = n + 1;
        for (int i = n; i > 0; i--) {
            l = min(l, i-a[i]+1);
            
            if (i >= l) b[i] = 1;
            else b[i] = 0;
        }
        
        for (int i = 1; i <= n; i++)
            printf("%d ", b[i]);
        puts("");
    }
    
    return 0;
}