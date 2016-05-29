#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SimpleSieve(long long limit, long long prime[], long long *c, long long n, int *counter, long long lucky[], int *lucky_counter)
{
	bool mark[limit + 1];
	long long p;
	long long i;
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
			if (n % p == 0) {
				*counter = *counter + 1;
			}
			if (*counter >= 3) {
				lucky[*lucky_counter] = n;
				*lucky_counter = *lucky_counter + 1;
				return;
			}
		}
	}
}

void SegmentedSieve(long long n, int *counter, long long lucky[], int *lucky_counter)
{
	long long limit, i, j, c = 0;
	limit = sqrt(n) + 1;
	long long prime[50];
	SimpleSieve(limit,prime,&c,n,counter,lucky,lucky_counter);
	if (*counter >= 3) {
		return;
	}
	
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
				if (n % i == 0) {
					*counter = *counter + 1;
				}
				if (*counter >= 3) {
					lucky[*lucky_counter] = n;
					*lucky_counter = *lucky_counter + 1;
					return;
				}
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
	long long lucky[1000];
	int lucky_counter = 0;
	long long t1 = 30;
	while (lucky_counter != 1000) {
		int counter = 0;
		SegmentedSieve(t1,&counter,lucky,&lucky_counter);
		t1++;
	}
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", lucky[n - 1]);
	}
	return 0;
}
