#include <stdio.h>
#include <math.h>

int main()
{
	long long t, i;
	double n,k,m,a,b,c;
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		scanf("%lf %lf %lf", &n,&k,&m);
		if (n > m) {
			printf("0\n");
			continue;
		}
		a = log10((long long)m/(long long)n);
		b = log10((long long)k);
		c = a/b;
		printf("%lld\n", (long long)c);
	}
	return 0;
}
