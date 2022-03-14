#include <iostream>
#include <vector>

using namespace std;

vector<int> mult(vector<int> &a, int b) {
    vector<int> c;
    
    for (int i = 0, t = 0; i < a.size() || t; i++) {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

int main() {
    string a;
    int b;
    vector<int> x;
    cin >> a >> b; 
    for (int i = a.size() - 1; i >= 0; i--)
        x.push_back(a[i] - '0');    


    auto c = mult(x, b);
    for (int i = c.size() - 1; i >= 0; i--)
        printf("%d", c[i]);
    
    return 0;
}