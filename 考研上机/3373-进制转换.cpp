#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;

vector<int> div(vector<int> A, int b)
{
    vector<int> C;
    for (int i = A.size() - 1, r = 0; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string s;
    while (cin >> s) {
        vector<int> A;
        for (int i = 0; i < s.size(); i++) {
            A.push_back(s[s.size()-i-1] - '0');
        }
        
        string res;
        if (s == "0") res = "0";
        else {
            while (A.size()) {
                res += to_string(A[0]%2);
                A = div(A, 2);
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
};