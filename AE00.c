#include <stdio.h>
int main()
{
	long long n, i, j, c = 0;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i * j <= n) {
				c++;
			} else {
				break;
			}
		}
	}
	printf("%lld\n", c);
	return 0;
}
