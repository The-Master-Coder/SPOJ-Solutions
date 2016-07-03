#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
	int t, i, j, a, b, c, g;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		c = 2;
		g = gcd(a,b);
		if (g == 1) {
			printf("1\n");
			continue;
		}
		for (j = 2; j <= sqrt(g); j++) {
			if (g % j == 0) {
				c++;
				if (g/j != j) {
					c++;
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
