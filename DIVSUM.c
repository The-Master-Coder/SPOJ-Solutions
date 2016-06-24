#include <stdio.h>
#include <math.h>

int main()
{
	int t, i, j, n;
	long long sum;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n == 1 || n == 0) {
			printf("0\n");
			continue;
		}
		sum = 1;
		for (j = 2; j <= sqrt(n); j++) {
			if (n % j == 0) {
				sum = sum + j;
				if (n/j != j) {
					sum = sum + n/j;
				}
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
