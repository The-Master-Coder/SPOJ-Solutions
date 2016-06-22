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
	int n, i, A[500000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	quick_sort(A,0,n-1);
	if (A[0] != A[1]) {
		printf("%d\n", A[0]);
	} else if (A[n-1] != A[n-2]) {
		printf("%d\n", A[n-1]);
	} else {
		for (i = 1; i <= n-2; i++) {
			if (A[i] != A[i-1] && A[i] != A[i+1]) {
				printf("%d\n", A[i]);
			}
		}
	}
	return 0;
}
