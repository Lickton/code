#include <iostream>

using namespace std;

const int N = 100010;
int stk[N], tt, m;

int main()
{
    cin >> m;
    string op;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[tt++] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            cout << (tt == 0 ? "YES" : "NO") << endl;
        } else if (op == "query") {
            cout << stk[tt-1] << endl;
        }
    }

    return 0;
}