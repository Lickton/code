#include <iostream>
#include <ctype.h>
#include <cstring>

using namespace std;

const int N = 20;

char str[N];

int main()
{
    cin >> str;
    int res = 0, n = strlen(str);
    for (int i = 0, k = 1; i < n - 1; i++) {
        if (!isdigit(str[i])) continue;
        res += (str[i] - '0') * (k++);
    }

    if (res % 11 == 10) res = 'X';
    else res = (res % 11) + '0';

    if (res == str[n-1]) cout << "Right" << endl;
    else {
        str[n-1] = (char)res;
        cout << str << endl;
    }

    return 0;
}