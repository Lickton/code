#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l-1] << endl;
    }
    
    return 0;
}