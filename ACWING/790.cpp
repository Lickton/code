#include <iostream>

using namespace std;

int main() {
    double x;
    cin >> x;
    
    double l = -10000, r = 10000;   //使可以取到的数的范围在给定的范围以内
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x)
            r = mid;
        else
            l = mid;
    }
    
    printf("%lf", l);
    return 0;
}