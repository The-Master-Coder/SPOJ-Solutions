#include<stdio.h>
int main()
{
	int t, i;
	long long n, d, s;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		while(1) {
			d = n;
			s = 0;
			while(d != 0) {
				s = s + d%10;
				d = d/10;
			}
			if (n%s == 0) {
				printf("%lld\n", n);
				break;
			}
			n++;
		}	
	}
	return 0;
}
