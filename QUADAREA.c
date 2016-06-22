#include <stdio.h>
#include <math.h>

int main()
{
	int t, i;
	double a, b, c, d, s;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		s = (a+b+c+d)/2;
		printf("%.2lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}
	return 0;
}
