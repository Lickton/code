#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m, i, j;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    i = j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j])
            i++;
        j++;
    }

    if (i == n)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
