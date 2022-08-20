#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 20;

int n, cnt = 20;
vector<int> state1;
stack<int> state2;
int state3 = 1;

void dfs()
{
    if (!cnt) return;
    if (state1.size() == n) {
        for (auto x : state1)
            cout << x;
        cout << endl;
        return;
    }
    if (state2.size()) {
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back());
        state1.pop_back();
    }

    if (state3 <= n) {
        state2.push(state3);
        state3++;
        dfs();
        state3--;
        state2.pop();
    }
}

int main()
{
    cin >> n;
    dfs();
    return 0;
} 