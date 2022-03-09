#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &x, vector<int> &y) {
    int cf = 0; // cf for carry flag
    vector<int> z;
    for (int i = 0; i < x.size() || i < y.size(); i++) {
        if (i < x.size())
            cf += x[i];
        if (i < y.size())
            cf += y[i];
        z.push_back(cf % 10);
        cf /= 10;
    }

    if (cf)
        z.push_back(cf);

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

    vector<int> c = add(x, y);
    
    for (int i = c.size() - 1; i >= 0; i--)
        printf("%d", c[i]);

    return 0;
}