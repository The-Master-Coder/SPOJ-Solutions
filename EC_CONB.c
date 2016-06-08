#include <stdio.h>
#include <math.h>

void d_to_b(long long x, long long A[], long long *c)
{
	if (x == 0) {
		return;
	}
	long long r;
	r = x % 2;
	d_to_b(x / 2,A,c);
	A[*c] = r;
	*c = *c + 1;
}

int main()
{
	long long n, i, j, x, r, A[100], c, nn;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &x);
		if (x % 2 == 0) {
			c = 0;
			nn = 0;
			d_to_b(x,A,&c);
			for (j = 0; j < c; j++) {
				if (A[j] == 1) {
					nn = nn + (long long)pow(2,j);
				}
			}
			printf("%lld\n", nn);			
		} else {
			printf("%lld\n", x);
		}
	}
	return 0;
}
