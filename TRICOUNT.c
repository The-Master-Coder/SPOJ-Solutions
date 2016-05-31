#include <stdio.h>
int main()
{
	long long t, i;
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", (n*(n+2)*(2*n + 1)) / 8);
	}
	return 0;
}
