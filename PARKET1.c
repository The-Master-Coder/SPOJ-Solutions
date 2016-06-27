#include <stdio.h>
#include <math.h>

int main()
{
	int r, b, t, x, y;
	scanf("%d %d", &r, &b);
	t = (int)sqrt(r*r-8*r-16*b+16);
	x = (r+4+t)/4;
	y = (r+4-t)/4;
	if (x > y) {
		printf("%d %d\n", x, y);
	} else {
		printf("%d %d\n", y, x);
	}
	return 0;
}
