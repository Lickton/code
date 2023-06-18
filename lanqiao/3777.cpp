#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 210;

void update(char& c)
{
    c = (char)('W' + 'B' - c);
}

bool check(string s, char c)
{
    vector<int> res;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] != c) {
            update(s[i]);
            update(s[i+1]);
            res.push_back(i);
        }
    }
    
    if (s.back() != c) return false;
    
    cout << res.size() << endl;
    for (auto e : res) printf("%d ", e+1);
    if (res.size()) puts("");
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        if (!check(s, 'B') && !check(s, 'W')) puts("-1");
    }
    
    return 0;
}