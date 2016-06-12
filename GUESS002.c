#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, x;
	while(scanf("%lf %lf", &a, &b) != EOF) {
		x = pow(a,b);
		printf("%.1lf\n", x);
	}
	return 0;
}
