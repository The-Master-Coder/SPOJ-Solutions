#include <stdio.h>
#include <math.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		double w,v,u,U,V,W,w1,v1,u1,vol;
		scanf("%lf %lf %lf %lf %lf %lf", &w,&v,&u,&U,&V,&W);
		w1 = u*u + v*v - W*W;
		v1 = u*u + w*w - V*V;
		u1 = v*v + w*w - U*U;
		
		vol = (double)1/12 * sqrt(4*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1 + u1*v1*w1);
		printf("%.4lf\n", vol);
	}
	return 0;
}
