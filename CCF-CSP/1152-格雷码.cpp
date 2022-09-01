#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

string f(int n, ULL k)
{
    if (n == 0) return "";

    if (k < (1ull << n-1)) return "0" + f(n-1, k);
    else {
        ULL t = (1ull << n) - 1;
        if (n == 64) t -= 1;
        return "1" + f(n-1, t - k);
    }
}

int main()
{
    int n;
    ULL k;
    cin >> n >> k;
    cout << f(n, k) << endl;
    return 0;
}