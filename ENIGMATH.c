#include <stdio.h>

long long gcd(long long p, long long q)
{
	long long r;
	while (q % p != 0) {
		r = q % p;
		q = p;
		p = r;
	}
	return p;
}

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		long long a, b, x;
		scanf("%lld %lld", &a, &b);
		if (b % a == 0) {
			x = a;
		} else {
			x = gcd(a,b);
		}
		a = a / x;
		b = b / x;
		printf("%lld %lld\n", b, a);
	}
	return 0;
}
