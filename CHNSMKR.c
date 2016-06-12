#include <stdio.h>
int main()
{
	int x, y, p, q, r,i,v,flag=0;
	scanf("%d%d",&x,&y);
	while (x != 0 && y != 0) {
		for (i = x; i <= y; i++) {
			p = y/i;
			if (p>=20 && p<=25) {
				flag=1;
				v = p;
				while (v == p) {
					i++;
					v = y/i;
				}
				printf("%d %d\n", i-1, y-((i-1)*p));
				break;
			}
			flag=2;
		}
		if (flag==2) {
			printf("Not Possible\n");
		}
		scanf("%d%d",&x,&y);
	}
	return 0;
}
