#include <stdio.h>

void push(int i,int S[],int *t)
{	
	*t = *t + 1;
	S[*t] = i;
	return;
}

int pop(int S[], int *t)
{
	int x;
	x = S[*t];
	*t = *t - 1;
	return x;
}

int is_empty(int *t)
{
	if (*t == -1) {
		return 1;
	} else {
		return 0;
	}
}

int top(int S[], int t)
{
	return S[t];
}

int main()
{
	int n, i, A[1000], R[1000], S[1000], c, f, t, j;
	scanf("%d", &n);
	while (n != 0) {
		t = -1;
		c = f = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		for (i = 0; i < n-1; i++) {
			if (A[i] < A[i+1]) {
				while(!is_empty(&t) && A[i] > top(S,t)) {
					R[c] = pop(S,&t);
					c++;
				}
				R[c] = A[i];
				c++;
			} else {
				while(!is_empty(&t) && A[i] > top(S,t)) {
					R[c] = pop(S,&t);
					c++;
				}
				push(A[i],S,&t);
			}
		}
		
		while(!is_empty(&t) && A[n-1] > top(S,t)) {
					R[c] = pop(S,&t);
					c++;
		}
		push(A[n-1],S,&t);
		while (!is_empty(&t)) {
			R[c] = pop(S,&t);
			c++;
		}
		for (i = 0; i < n-1; i++) {
			if (R[i] > R[i+1]) {
				f = 1;
				break;
			} else {
				f = 2;
			}
		}
		if (f == 1) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
		scanf("%d", &n);
	}
	return 0;
}
