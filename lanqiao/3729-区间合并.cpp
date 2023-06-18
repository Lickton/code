#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 200010;

int T, n;
int a[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        vector<PII> b;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int st = max(i-a[i]+1, 1), ed = i;
            if (a[i]) b.push_back({st, ed});
        }
        
        sort(b.begin(), b.end());
        
        vector<PII> res;
        int st = -2e9, ed = -2e9;
        for (auto seg : b) {
            if (ed < seg.x) {
                if (st != -2e9) res.push_back({st, ed});
                st = seg.x, ed = seg.y;
            } else 
                ed = max(seg.y, ed);
        }
        
        if (st != -2e9) res.push_back({st, ed});
        
        // output
        // for (auto seg : res) {
        //     printf("%d %d  ",seg.x, seg.y);
        // }
        // puts("");
        
        if (res.size()) {
            PII cur = res[0];
            for (int i = 1, j = 0; i <= n; i++) {
                if (i < cur.x || i > cur.y) printf("0 ");
                else {
                    printf("1 ");
                    if (i == cur.y && j < res.size() - 1) cur = res[++j];
                }
            }
            puts("");
        } else {
            for (int i = 1; i <= n; i++)
                printf("0 ");
            puts("");
        }
    }
    
    return 0;
}