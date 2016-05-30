#include <stdio.h>
int main()
{
	int t, i;
	scanf("%d", &t);
	long long n, j, a, x, p;
	for (i = 1; i <= t; i++) {
		long long flag = 0;
		scanf("%lld", &n);
		if (n < 8) {
			printf("Case %d: -1\n",i);
		} else {
			if (n % 3 == 0 && n % 5 != 0) {
				for (j = n - 3; j >= 3; j = j - 3) {
					p = n - j;
					if (p % 5 == 0) {
						flag = 1;
						printf("Case %d: %lld\n", i, j);
						break;
					} else {
						flag = 2;
					}
				}
				if (flag == 2) {
					printf("Case %d: -1\n",i);
				}
			} else if (n % 3 == 0 && n % 5 == 0) {
				for (j = n - 3; j >= 3; j = j - 3) {
					p = n - j;
					if (p % 5 == 0) {
						flag = 1;
						printf("Case %d: %lld\n", i, j);
						break;
					} else {
						flag = 2;
					}
				}
				if (flag == 2) {
					printf("Case %d: -1\n",i);
				}
			} else {
				x = (n / 3) * 3;
				for (j = x; j >= 3; j = j - 3) {
					p = n - j;
					if (p % 5 == 0) {
						flag = 1;
						printf("Case %d: %lld\n", i, j);
						break;
					} else {
						flag = 2;
					}
				}
				if (flag == 2) {
					printf("Case %d: -1\n",i);
				}
			}
		}
	}
	return 0;
}
