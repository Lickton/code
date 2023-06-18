#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

LL n, res;
LL q[N], sum[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        sum[i] = sum[i - 1] + q[i];
    }

    if (sum[n] % 3)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 3, cnt = 0; i <= n; i++)
    {
        if (sum[i - 2] == sum[n] / 3)
            cnt++;
        if (sum[n] - sum[i - 1] == sum[n] / 3)
            res += cnt;
    }

    cout << res << endl;
    return 0;
}