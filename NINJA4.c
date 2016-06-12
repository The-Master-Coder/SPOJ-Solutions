#include <stdio.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	long long n, x, y;
	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		if (n % 2 == 0) {
			if (n % 4 == 0) {
				x = -(n/2);
				y = x;
			} else {
				x = n/2;
				y = x + 1;
			}
		} else {
			if ((n+1) % 4 == 0) {
				y = (n+1)/2;
				x = -y;
			} else {
				x = (n+1)/2;
				y = -(x - 1);
			}
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
}
