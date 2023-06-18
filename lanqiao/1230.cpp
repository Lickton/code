#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

LL n, k, res;
LL s[N], mod[N];


int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i-1];
        s[i] %= k;
    }

    mod[0]++;
    for (int i = 1; i <= n; i++) {
        res += mod[s[i]];
        mod[s[i]]++;
    }

    cout << res << endl;
    return 0;
}