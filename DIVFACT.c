#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SieveOfEratosthenes(int P[], int n)
{
	int x = 0;
	bool prime[n + 1];
	int p;
	int i;
	for (i = 0; i <= n; i++) {
		prime[i] = true;
	}
	for (p = 2; p <= (int)sqrt(n); p++) {
		if (prime[p] == true) {
			for (i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}
	
	for (p = 2; p <= n; p++) {
		if (prime[p] == true) {
			P[x] = p;
			x++;
		}
	}
}


int main()
{
	int n, i, j, k, count, c, x, t, test, num;
	int P[5133];
	SieveOfEratosthenes(P,50000);
	long long s, e;
	scanf("%d", &test);
	for (k = 0; k < test; k++) {
		s = 1;
		scanf("%d", &n);
	    for(i = 0; P[i] <= n && i < 5133; i++) {
	        num = n;
	        e = 0;
	        while(num) {
				e = e + num/P[i];
	            num = num/P[i];
	        }
	        s = (s*(e+1))%1000000007;
	    }
			printf("%lld\n", s);
	}
	return 0;
}
