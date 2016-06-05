#include <stdio.h>
#include <math.h>

double area(double a, double b, double c)
{
	double s, area;
	s = (double)(a + b + c) / 2;
	area = sqrt(s *(s-a)*(s-b)*(s-c));
	return area;
}

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		double w,v,u,U,V,W,w1,v1,u1,vol,a1,a2,a3,a4,r;
		scanf("%lf %lf %lf %lf %lf %lf", &w,&v,&u,&U,&V,&W);
		w1 = u*u + v*v - W*W;
		v1 = u*u + w*w - V*V;
		u1 = v*v + w*w - U*U;
		
		vol = (double)1/12 * sqrt(4*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1 + u1*v1*w1);
		a1 = area(U,v,w);
		a2 = area(u,V,w);
		a3 = area(u,v,W);
		a4 = area(U,V,W);
		
		r = (3*vol)/(a1+a2+a3+a4);
		printf("%.4lf\n", r);
	}
	return 0;
}
