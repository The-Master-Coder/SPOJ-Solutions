#include <stdio.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		double n, x;
		scanf("%lf", &n);
		x = n / (n+1);
		printf("%.8lf\n", x);
	}
	return 0;
}
