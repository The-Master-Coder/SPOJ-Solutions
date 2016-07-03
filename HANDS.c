#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long long t, i, h, m, H, M, c, x, y;
	double f1, f2, f3;
	f1 = (double)12/11;
	char a[10], b[10];
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		scanf(" %[^\n]s", a);
		scanf(" %[^\n]s", b);
		c = 0;
		h = (a[0]-48)*10 + (a[1] - 48);
		m = (a[3]-48)*10 + (a[4] - 48);
		H = (b[0]-48)*10 + (b[1] - 48);
		M = (b[3]-48)*10 + (b[4] - 48);
		if (h > 0 && h < 11) {
			f2 = f1*h*60;
		} else if (h > 12 && h < 23) {
			f2 = f1*(h-12)*60;
		}
		x = f2;
		x = x%60;
		if (H > 0 && H < 11) {
			f3 = f1*H*60;
		} else if (H > 12 && H < 23) {
			f3 = f1*(H-12)*60;
		}
		y = f3;
		y = y%60;
		if ((h==H) && (m==M)) {
			printf("%lld\n", c);
			continue;
		}
		if ((h == 0 && H == 0) || (h == 12 && H == 12) || (h == 11 && H == 11) || (h == 23 && H == 23)) {
			printf("%lld\n", c);
			continue;
		}
		c = c + (H-h-1);
		if (h < 11 && H > 11) {
			c--;
		}
		if (h>0 && h<11) {
			if (m <= x) {
				c++;
			} 
		} else if (h>12 && h < 23) {
			if (m <= x) {
				c++;
			}
		}
		if (H>0 && H<11) {
			if (M > y) {
				c++;
			}
		} else if (H == 12) {
			if (M >= 0) {
				c++;
			} 
		} else if (H > 12  && H < 23) {
			if (M > y) {
				c++;
			}
		}
		printf("%lld\n", c);
	}
	return 0;
}
