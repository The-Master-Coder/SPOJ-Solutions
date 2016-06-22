#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while (n != 0) {
		printf("%.2f\n", (n*n)/6.283184);
		scanf("%d",&n);
	}
	return 0;
}
