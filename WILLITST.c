#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	if (n <= 2 || (n & (n-1)) == 0) {
		printf("TAK\n");
	} else {
		printf("NIE\n");
	}
	return 0;
}
