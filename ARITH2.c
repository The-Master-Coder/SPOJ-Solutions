#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return 1;
	} else {
		return 0;
	}
}

long long evaluate(char c, long operand1, long operand2)
{
	if (c == '+') {
		return operand1 + operand2;
	}else if (c == '-') {
		return operand1 - operand2;
	}else if (c == '*') {
		return operand1 * operand2;
	}else if (c == '/') {
		return operand1 / operand2;
	}	
}

int is_numeric_digit(char c)
{
	if (c >= '0' && c <= '9') {
		return 1;
	} else {
		return 0;
	}
}

int is_empty(int *f,int *r)
{
	if (*f == -1 && *r == -1) {
		return 1;
	} else {
		return 0;
	}
}

char deque1(char q1[],int *f,int *r)
{
	char t;
	if (*f == *r) {
		t = q1[*f];
		*f = *r = -1;
	} else {
		t = q1[*f];
		*f = *f + 1;
	}
	return t;
}

void enque1(char q1[],char n,int *f,int *r)
{
	if (is_empty(f,r)) {
		*f = *r = 0;
	} else {
		*r = *r + 1;
	}
	q1[*r] = n;
}

long long deque2(long long q2[],int *f,int *r)
{
	long long t;
	if (*f == *r) {
		t = q2[*f];
		*f = *r = -1;
	} else {
		t = q2[*f];
		*f = *f + 1;
	}
	return t;
}

void enque2(long long q2[], long long n,int *f,int *r)
{
	if (is_empty(f,r)) {
		*f = *r = 0;
	} else {
		*r = *r + 1;
	}
	q2[*r] = n;
}

int main()
{
	long long t, i, j, k, l, o;
	char s[100000], q1[100000], c;
	int f1, f2, r1, r2;
	long long q2[100000], a, b, r;
	scanf("%lld", &t);
	for (i = 0; i < t; i++) {
		scanf(" %[^\n]s", s);
		f1 = f2 = r1 = r2 = -1;
		l = strlen(s);
		for (j = 0; j < l; j++) {
			if (s[j] == ' ' || s[j] == '=') {
				continue;
			} else if (is_numeric_digit(s[j])) {
				o = 0; 
				while(j < l && is_numeric_digit(s[j])) {
					o = (o * 10) + (s[j] - '0'); 
					j++;
				}
				j--;
				enque2(q2,o,&f2,&r2);
			} else if (is_operator(s[j])) {
				enque1(q1,s[j],&f1,&r1);
			}
		}
		a = deque2(q2,&f2,&r2);
		b = deque2(q2,&f2,&r2);
		r = evaluate(deque1(q1,&f1,&r1), a, b);
		while (!is_empty(&f1,&r1)) {
			a = r;
			b = deque2(q2,&f2,&r2);
			r = evaluate(deque1(q1,&f1,&r1), a, b);
		}
		printf("%lld\n", r);
	}
	return 0;
}

