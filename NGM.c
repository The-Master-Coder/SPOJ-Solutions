#include <stdio.h>

int main()
{
	int n, i, f = 0;
	scanf("%d", &n);
	for (i = 1; i < 10; i++) {
		if ((n-i) % 10 == 0) {
			f = 1;
			break;
		} else {
			f = 2;
		}
	}
	if (f == 1) {
		printf("1\n%d\n",i);
	} else {
		printf("2\n");
	}
	return 0;
}
