#include <stdio.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		long long p, q, r, a, d, n, j;
		scanf("%lld %lld %lld", &p, &q, &r);
		n = (2*r)/(p+q);
		d = (q - p)/(n - 5);
		a = p - (2*d);
		printf("%lld\n", n);
		for (j = 0; j < n; j++) {
			printf("%lld ", a + (j*d));
		}
		printf("\n");
	}
	return 0;
}
