#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SimpleSieve(int limit, int prime[], int *c, int P[], int *count)
{
	bool mark[limit + 1];
	int p;
	int i;
	for (i = 0; i <= limit; i++) {
		mark[i] = true;
	}
	for (p = 2; p <= (int)sqrt(limit); p++) {
		if (mark[p] == true) {
			for (i = p * p; i <= limit; i += p) {
				mark[i] = false;
			}
		}
	}
	
	for (p = 2; p <= limit; p++) {
		if (mark[p] == true) {
			prime[*c] = p;
			*c = *c + 1;
			P[*count] = p;
			*count = *count + 1;
		}
	}
}

void SegmentedSieve(int P[], int *count, int n)
{
	int limit, i, j, c = 0;
	limit = sqrt(n) + 1;
	int prime[100000];
	SimpleSieve(limit,prime,&c,P,count);
	
	int low = limit;
	int high = 2 * limit;
	
	while (low < n) {
		bool mark[limit + 1];
		for (i = 0; i <= limit; i++) {
			mark[i] = true;
		}
		for (i = 0; i < c; i++) {
			int lolim = (low / prime[i]) * prime[i];
			if (lolim < low) {
				lolim = lolim + prime[i];
			}
			for (j = lolim; j < high; j = j + prime[i]) {
				mark[j - low] = false;
			}
		}
		
		for (i = low; i < high; i++) {
			if (mark[i - low] == true) {
				P[*count] = i;
				*count = *count + 1;
			}
		}
		low = low + limit;
		high = high + limit;
		if (high >= n) {
			high = n;
		}
	}
	
}

int main()
{
	int n, i, j, count = 0, c, x, t;
	scanf("%d", &n);
	int P[n], E[n];
	SegmentedSieve(P,&count,n);
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
