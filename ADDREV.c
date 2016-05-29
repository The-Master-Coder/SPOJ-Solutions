#include<stdio.h>
#include<math.h>
int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		int n1, n2, c1 = 0, c2 = 0, j, t1, l, t2, a, b, x = 0, y = 0, t3, c3 = 0, c, z = 0;
		scanf("%d %d", &n1, &n2);
		t1 = n1 % 10;
		t2 = n2 % 10;
		while (t1 == 0) {
			n1 = n1 / 10;
			t1 = n1 % 10;
		}
		while (t2 == 0) {
			n2 = n2 / 10;
			t2 = n2 % 10;
		}
		t1 = n1;
		t2 = n2;
		while (t1 != 0) {
			t1 = t1 / 10;
			c1++;
		}
		while (t2 != 0) {
			t2 = t2 / 10;
			c2++;
		}
		for (j = c1 - 1; j >= 0; j--) {
			a = n1 % 10;
			n1 = n1 / 10;
			x = x + a * (int)pow(10,j);
		}
		for (j = c2 - 1; j >= 0; j--) {
			b = n2 % 10;
			n2 = n2 / 10;
			y = y + b * (int)pow(10,j);
		}
		l = x + y;
		t3 = l % 10;
		while (t3 == 0) {
			l = l / 10;
			t3 = l % 10;
		}
		t3 = l;
		while (t3 != 0) {
			t3 = t3 / 10;
			c3++;
		}
		for (j = c3 - 1; j >= 0; j--) {
			c = l % 10;
			l = l / 10;
			z = z + c * (int)pow(10,j);
		}
		printf("%d\n", z);
	}
	return 0;
}
