#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    string s;
    
    cin >> a >> b >> s;
    vector<int> A;
    for (int i = 0; i < s.size(); i++) {
        char c = s[s.size() - i - 1];
        if (c >= 'A') A.push_back(c - 'A' + 10);
        else A.push_back(c - '0');
    }
    
    string res;
    if (s == "0") res = "0";
    else {
        while (A.size()) {
            int r = 0;
            for (int i = A.size() - 1; i >= 0; i--) {
                A[i] += r * a;
                r = A[i] % b;
                A[i] /= b;
            }
            while (A.size() && A.back() == 0) A.pop_back();
            if (r < 10) res += to_string(r);
            else res += r - 10 + 'a';
        }
        reverse(res.begin(), res.end());
    }
    
    cout << res << endl;
    
    return 0;
}