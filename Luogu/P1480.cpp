#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &a, long b, long &r) {
    vector<int> c;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

int main() {
    string a;
    long b, r = 0;
    vector<int> x;
    cin >> a >> b; 
    for (int i = a.size() - 1; i >= 0; i--)
        x.push_back(a[i] - '0');

    auto c = div(x, b ,r);
    for (int i = c.size() - 1; i >= 0 ; i--)
        printf("%d", c[i]);

    return 0;
}