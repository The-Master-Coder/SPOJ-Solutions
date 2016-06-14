#include <stdio.h>

int main()
{
	int t, i;
	long long k;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &k);
		printf("%lld\n", 192+(k-1)*250);
	}
	return 0;
}
