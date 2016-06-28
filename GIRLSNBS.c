#include <stdio.h>

int main()
{
	int g, b;
	scanf("%d %d", &g, &b);
	while (g != - 1 && b != -1) {
		if (g == 0 && b == 0) {
			printf("0\n");
		} else if (g == b) {
			printf("1\n");
		} else if (g > b) {
			b++;
			if (g % b == 0) {
				printf("%d\n", g/b);
			} else {
				printf("%d\n", (g/b) + 1);
			}
		} else {
			g++;
			if (b % g == 0) {
				printf("%d\n", b/g);
			} else {
				printf("%d\n", (b/g) + 1);
			}
		}
		scanf("%d %d", &g, &b);
	}
	return 0;
}
