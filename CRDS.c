#include <stdio.h>
int main()
{
	int t, i;
	long long n;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		printf("%lld\n", ((n*(3*n+1))/2) % 1000007);
	}
	return 0;
}
