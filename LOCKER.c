#include <stdio.h>

typedef long long int ll;

ll mulmod(ll a, ll b, ll m)
{
    ll r = 0;
    a = a % m;
    while (b > 0) {
        if (b & 1) {
        	r = (r + a) % m;
		}
        a = (a * 2) % m;
        b = b >> 1;
    }
    return r % m;
}

ll power(ll x,unsigned long long y, ll p)
{
    ll r = 1;
	x = x%p;     
    while (y > 0) {
        if (y & 1) {
        	r = (r*x) % p;
		}
        y = y>>1; // y = y/2;
        x = (x*x) % p;  
    }
    return r;
}

int main()
{
	int t, i;
	ll n, c1, c2, a, b, c;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		c1 = 0;
		while (n%3 != 0) {
			n=n-2;
			c1++;
		}
		c2 = n/3;
		a = power(2,c1,1000000007);
		b = power(3,c2,1000000007);
		c = mulmod(a,b,1000000007);
		printf("%lld\n", c);
	}
	return 0;
}
