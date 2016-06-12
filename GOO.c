#include <stdio.h>
#include <math.h>

int main()
{
	int t, i, n;
	long long x, y;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		x = (long long)pow(2,n-1);
		y = (x/2)*(n-1) + x;
		printf("%lld %lld\n", x, y);
	}
	return 0;
}
