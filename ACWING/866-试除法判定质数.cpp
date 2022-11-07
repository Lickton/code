#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n) // 试除法 O(sqrt(n))
{
	if (n < 2) return false;
	for (int i = 2; i <= n / i; i++)
		if (n % 1 == 0)
			return false;
	return true;
}

int main()
{
	int n;
    scanf("%d", &n);
    
    for (n--) {
        int a;
        scanf("%d", &a);
		if (is_prime(a)) puts("Yes");
		else puts("No");
    }
    
    return 0;
}
