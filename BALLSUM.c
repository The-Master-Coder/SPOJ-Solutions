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
	long long n, k ;
	scanf("%lld", &n);
	scanf("%lld", &k);
	while (n != -1 && k != -1) {
		long long p = 0, q, i, t;
		q = (n * (n-1)) / 2;
		for(i = k - 2; i > 0; i = i - 2) {
			p = p + i;
		}
		if (p == 0) {
			printf("%lld\n", p);
			scanf("%lld", &n);
			scanf("%lld", &k);
			continue;
		}
		if (p / q == 1) {
			printf("1\n");
			scanf("%lld", &n);
			scanf("%lld", &k);
			continue;
		}
		if (q % p == 0) {
			t = p;
		} else {
			t = gcd(p,q);
		}
		p = p / t;
		q = q / t;
		printf("%lld/%lld\n", p, q);
		scanf("%lld", &n);
		scanf("%lld", &k);
	}
	return 0;
}
