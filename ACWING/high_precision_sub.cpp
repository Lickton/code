#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &x, vector<int> &y) {
    if (x.size() != y.size())
        return x.size() > y.size();
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] != y[i])
            return x[i] > y[i];
    }
    return true;
}

vector<int> sub(vector<int> &x, vector<int> &y) {
    vector<int> z;
    for (int i = 0, t = 0; i < x.size(); i++) {
        t = x[i] - t;
        if (i < y.size())
            t -= y[i];
        z.push_back((t + 10) % 10);
        t = (t < 0 ? 1 : 0);
    }
    while (z.size() > 1 && z.back() == 0)
        z.pop_back();
    return z;
}

int main() {
    string a, b;
    vector<int> x, y;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        x.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        y.push_back(b[i] - '0');

    if (cmp(x, y)) {
        auto z = sub(x, y);
        for (int i = z.size() - 1; i >= 0; i--)
            printf("%d", z[i]);
    } else {
        auto z = sub(y, x);
        printf("-");
        for (int i = z.size() - 1; i >= 0; i--)
            printf("%d", z[i]);
    }
    return 0;
}