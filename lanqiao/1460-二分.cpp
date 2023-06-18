#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string str;
unordered_map<string, int> S;

bool check(int mid)
{
    for (int i = 0; i + mid - 1 < n; i++) {
        string s = str.substr(i, mid);
        if (S[s]) return false;
        S[s]++;
    }
}

int main()
{
    cin >> n >> str;

    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;

    return 0;
}