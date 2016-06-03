#include <stdio.h>

void swap(int A[],int a,int b)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

int partition(int A[],int start,int end)
{
	int pivot, i, p_index;
	pivot = A[end];
	p_index = start;
	for(i = start; i < end; i++) {
		if (A[i] <= pivot) {
			swap(A,i,p_index);
			p_index++;
		}
	}
	swap(A,p_index,end);
	return p_index;
}

void quick_sort(int A[],int start,int end)
{
	int p_index;
	if (start >= end) {
		return;
	}
	p_index = partition(A,start,end);
	quick_sort(A,start,p_index - 1);
	quick_sort(A,p_index + 1,end);
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n != -1) {
		int i, A[n], flag = 0;
		long long sum = 0, v, c = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			sum = sum + A[i];
		}
		if (sum % n != 0) {
			flag = 1;
			printf("-1\n");
		}
		if (flag != 1) {
			quick_sort(A,0,n - 1);
			v = sum / n;
			for (i = n - 1; i >= 0; i--) {
				if (A[i] > v) {
					c = c + A[i] - v;
				}
			}
			printf("%lld\n", c);
		}
		scanf("%d", &n);
	}
	return 0;
}
