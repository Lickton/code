#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;

int n;
char str[N];

int main()
{
    cin >> n >> str;
    
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != 'x')
            continue;
        
        int j = 0;
        for (; i + j < n && str[i+j] == 'x'; j++) {
            if (j > 1) {
                res++;
            }
        }
        i += j;
    }
    
    cout << res << endl;
    
    return 0;
}