#include <stdio.h>

int main()
{
	int t, i, n;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("%d\n", n/2);
		} else {
			printf("%d\n", (n+1)/2);
		}
	}
	return 0;
}
