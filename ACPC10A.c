#include<stdio.h>
int main()
{
	int p,q,r;
	scanf("%d %d %d",&p,&q,&r);
	while (p!= 0 || q!= 0 || r!=0) {
		if(q-p == r-q) {
			printf("AP %d\n", (r+q-p));
		} else {
			printf("GP %d\n", (q/p)*r);
		}
		scanf("%d %d %d",&p,&q,&r);
	}
	
}
