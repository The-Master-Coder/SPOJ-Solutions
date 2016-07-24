#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SieveOfEratosthenes(int P[], int *count, int n)
{
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
			P[*count] = p;
			*count = *count + 1;
		}
	}
}

int main()
{
	int n, i, j, count = 0, c, x, t;
	scanf("%d", &n);
	int P[n], E[n];
	SieveOfEratosthenes(P,&count,n);
	for (i = 0; i < count; i++) {
		c = 0;
		x = P[i];
		for (j = 1; j <= n; j++) {
			t = j;
			if (t % x == 0) {
				while (t % x == 0) {
					t = t / x;
					c++;
				}
			}
		}
		E[i] = c;
	}
	for (i = 0; i < count; i++) {
		if (i == count - 1) {
			printf("%d^%d\n", P[i], E[i]);
			break;
		}
		printf("%d^%d * ", P[i], E[i]);
	}
	return 0;
}
