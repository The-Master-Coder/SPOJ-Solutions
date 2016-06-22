#include <stdio.h>

int main()
{
	int t, i;
	long long n;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		if (n%2 == 1) {
			printf("%lld\n",n/2);
		} else {
			if ((n/2) % 2 == 0) {
				printf("%lld\n", n/2 - 1);
			} else {
				printf("%lld\n", n/2 - 2);
			}
		}
	}
	return 0;
}
