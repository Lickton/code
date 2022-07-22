#include <iostream>

using namespace std;

const int N = 3;
int t;
int door[N];

int main()
{
    int key;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int key;
        cin >> key;
        for (int j = 0; j < N; j++)
            cin >> door[j];

        if (door[key-1] == 0 || door[door[key-1]-1] == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}