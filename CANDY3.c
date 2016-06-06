#include <stdio.h>

int main()
{
	long long t, i;
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		long long n, j, sum = 0, x;
		scanf("%lld", &n);
		for (j = 0; j < n; j++) {
			scanf("%lld", &x);
			x = x % n;
			sum = sum + x;
		}
		if (sum % n == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
