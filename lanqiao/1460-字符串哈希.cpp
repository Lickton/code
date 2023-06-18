#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 110, M = 1e5, P = 131;

int n;
char str[N];
ULL h[M], p[M];
int ha[M];

ULL get(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}

int main()
{
    cin >> n;
    scanf("%s", str + 1);
    
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    
    int flag;
    for (int i = 1; i <= n; i++) {
        flag = 1;
        for (int j = 1; j + i <= n; j++) {
            ULL x = get(j, j+i);
            if(ha[x] == 0) {
                ha[x]++;
            } else {
                flag = 0;
                break;
            }
        }
        
        if (flag) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}