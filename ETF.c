#include <stdio.h>
 
int etf(int n)
{    
    int p, r = n;
    for (p = 2; p*p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
            	n = n/p;
			}
            r = r - (r / p);
        }
    }
    if (n > 1) {
    	r = r - (r / n);
	}
    return r;
}

int main()
{
    int t, i, n;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", etf(n));
	}
	return 0;
}
