#include <stdio.h>
int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		long long n, x, y, j;
		scanf("%lld %lld %lld", &n, &x, &y);
		for (j = x; j < n; j = j + x) {
			if (j % y != 0) {
				printf("%lld ", j);
			}
		}
		printf("\n");
	}
	return 0;
}
