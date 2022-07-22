#include <iostream>

using namespace std;

const int N = 100010;

int q[N];
int hh, tt = -1;

int m;

int main()
{
    cin >> m;
    string op;
    while (m--) {
        cin >> op;
        if (op == "empty")
            cout << (hh > tt ? "YES" : "NO") << endl;
        else if (op == "push") {
            int x; cin >> x;
            q[++tt] = x;
        } else if (op == "pop")
            hh++;
        else if (op == "query")
            cout << q[hh] << endl;
    }

    return 0;
}