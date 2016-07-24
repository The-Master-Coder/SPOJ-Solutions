#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int binary_search(int A[],int start,int end,int value)
{
	int mid;
	if (start > end) {
		return 0;
	}
	mid = start + (end - start) / 2;
	if (A[mid] == value) {	
		return 1;
	} else if (value > A[mid]) {
		start = mid + 1;
		binary_search(A,start,end,value);
	} else {
		end = mid - 1;
		binary_search(A,start,end,value);
	}
}

int main()
{
	int n, m, i, j, c, a, b, t;
	int A[100000];
	scanf("%d", &t);
	for (j = 0; j < t; j++) {
		scanf("%d %d", &n, &m);
		c = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		quick_sort(A,0,n-1);
		for (i = 0; i < n; i++) {
			if (binary_search(A,0,n-1,m-A[i])) {
				c++;
			}
		}
		printf("%d\n", c/2);
	}	
	return 0;
}
