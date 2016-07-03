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
	int t, i, j, s, f, c, sum, x, flag;
	int A[1000];
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &s, &f);
		flag = 0;
		c = 0;
		sum = 0;
		x = f-1;
		for (j = 0; j < f; j++) {
			scanf("%d", &A[j]);
		}
		quick_sort(A,0,f-1);
		while (sum < s) {
			if (x < 0) {
				flag = 1;
				break;
			}
			sum = sum + A[x];
			x--;
			c++;
		}
		printf("Scenario #%d:\n", i);
		if (flag == 1) {
			printf("impossible\n");
			continue;
		}
		printf("%d\n", c);
	}
	return 0;
}
