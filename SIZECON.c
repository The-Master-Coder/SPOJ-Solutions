#include <stdio.h>

int main()
{
	int t,i,n,sum = 0;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n > 0) {
			sum = sum + n;
		}
	}
	printf("%d\n", sum);
	return 0;
}
