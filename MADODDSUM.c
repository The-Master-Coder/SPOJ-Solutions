#include <stdio.h>
int main()
{
	long long a, b, i, sum = 0;
	scanf("%lld", &a);
	scanf("%lld", &b);
	if (a % 2 == 1) {
		for (i = a; i <= b; i = i + 2) {
			sum = sum + i;
		}
	} else {
		for (i = a + 1; i <= b; i = i + 2) {
			sum = sum + i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
