#include <stdio.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		long long n, c = 0;
		scanf("%lld", &n);
		while (n >= 5) {
			n = n / 5;
			c = c + n;
		}
		printf("%lld\n", c);
	}
	return 0;
}
