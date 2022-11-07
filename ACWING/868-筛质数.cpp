#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes1(int n) // 朴素 O( n*ln(n) )
{
	for (int i = 2; i <= n; i++) {
		if (!st[i]) {
			primes[cnt++] = n;
		}
		for (int j = i + i; j <= n; j += i) st[j] = true;
	}
}

void get_primes2(int n) //  埃氏筛 1~n 有 n/ln(n) 个质数 O( n*log(log(n)) )
{
	for (int i = 2; i <= n; i++) {
		if (!st[i]) {
			primes[cnt++] = n;
			for (int j = i + i; j <= n; j += i)
				if (!st[j]) st[j] = true;
		}
	}
}

void get_primes3(int n) // 线性筛 
{
	for (int i = 2; i <= n; i++) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; j++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break; // primes[j]一定是i的最小质因子
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	get_primes3(n);
	printf("%d\n", cnt);

	return 0;
}
