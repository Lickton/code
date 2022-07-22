#include <iostream>

using namespace std;

const int N = 100010;
int m;

int e[N], l[N], r[N];
int idx, head = 0, tail = 1;

void init()
{
    r[head] = tail;
    l[tail] = head;
    idx = 2;
}

void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}


int main() {
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        int k, x;
        string op;
        cin >> op;
        if (op == "L") {
            cin >> x;
            add(head, x);
        } else if (op == "R") {
            cin >> x;
            add(l[tail], x);
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k+1], x);
        } else if (op == "IR") {
            cin >> k >> x;
            add(k+1, x);
        } else if (op == "D") {
            cin >> k;
            remove(k+1);
        }
    }

    for (int i = r[head]; i != tail; i = r[i])
        cout << e[i] << " ";

    return 0;    
}