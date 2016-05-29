#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SimpleSieve(int n, int prime[], int *c)
{
	bool mark[n + 1];
	int p;
	int i;
	for (i = 0; i <= n; i++) {
		mark[i] = true;
	}
	for (p = 2; p <= (int)sqrt(n); p++) {
		if (mark[p] == true) {
			for (i = p * p; i <= n; i += p) {
				mark[i] = false;
			}
		}
	}
	
	for (p = 2; p <= n; p++) {
		if (mark[p] == true) {
			prime[*c] = p;
			*c = *c + 1;
		}
	}
}

void SegmentedSieve(int n1, int n2)
{
	int prime[100000];
	int c = 0, i, j, k = 0, p, flag = 0;
	SimpleSieve((int)sqrt(n2),prime,&c);
	for (i = n1; i <= n2; i++) {
		if (i == 2 || i == 3) {
			printf("%d\n", i);
			continue;
		}
		for (k = 0; k < c; k++) {
			j = prime[k];
			if (j <= (int)sqrt(i)) {
				if (i % j == 0) {
					flag = 1;
					break;
				} else {
					flag = 2;
				}
			}
		}
		if (flag == 2) {
			printf("%d\n", i);
		}
	}
}

int main()
{
	int t, i;
	scanf("%d", &t);
	int n1, n2;
	for (i = 0; i < t; i++) {
		scanf("%d", &n1);
		scanf("%d", &n2);
		SegmentedSieve(n1,n2);
	}
	return 0;
}
