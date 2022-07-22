#include <iostream>

using namespace std;

const int N = 100010;
int m;

int e[N], ne[N];
int idx, head;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            int k;
            cin >> k;
            if (!k) head = ne[head];
            remove(k-1);
        } else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            add(k-1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";

    return 0;
}