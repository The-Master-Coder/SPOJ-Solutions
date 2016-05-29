#include<stdio.h>
int main()
{
	int n;
	int i;
	while (1) {
		int t = 0;
		scanf("%d", &n);
		if (n == 0) {
			break;
		} else {
			for (i = 1; i <= n; i++) {
				t = t + i*i;
			}
		}
		printf("%d\n", t);
	}
	return 0;
}
