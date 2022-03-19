#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, q[N] = {0}, s[N] = {0};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
        s[i] += s[i-1] + q[i];
    }
    int l, r;
    while (m--) {
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}