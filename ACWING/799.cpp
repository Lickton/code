#include <iostream>

using namespace std;

const int N = 100010;

int n;
int b[N], a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        b[a[i]]++;
        while (b[a[i]] > 1) {
            b[a[j]]--;
            j++;
        }

        res = max(res, i - j + 1);
    }

    cout << res << endl;
    return 0;
}