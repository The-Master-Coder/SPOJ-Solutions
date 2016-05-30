#include <stdio.h>
int main()
{
	long long t, i;
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		if (x - y != 0 && x - y != 2) {
			printf("No Number\n");
		} else if (x + y == 0) {
			printf("0\n");
		} else if (x == y && x % 2 == 0) {
			printf("%lld\n", x+x);
		} else if (x == y && x % 2 == 1) {
			printf("%lld\n", x+x-1);
		} else if (x % 2 == 0) {
			printf("%lld\n", x+y);
		} else if (x % 2 == 1) {
			printf("%lld\n", x+y-1);
		}
	}
	return 0;
}
