#include <stdio.h>
#include <limits.h>

void swap(int a,int b,int heap[])
{
	int temp;
	temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void max_heapify(int i,int n,int heap[])
{
	int l, r, largest;
	l = 2 * i;
	r = 2 * i + 1;
	largest = i;
	if (l <= n && heap[l] > heap[largest]) {
		largest = l;
	}
	if (r <= n && heap[r] > heap[largest]) {
		largest = r;
	}
	swap(largest,i,heap);
	if (largest != i) {
		max_heapify(largest,n,heap);
	}
}

void build_heap(int n,int heap[])
{
	int i;
	for(i = n/2; i >= 1; i--) {
		max_heapify(i,n,heap);
	}
}

int kth_smallest(int A[], int n, int k)
{
	int heap[k+1], i;
	heap[0] = INT_MAX;
	for (i = 1; i <= k; i++) {
		heap[i] = A[i-1];
	}
	build_heap(k,heap);
	for (i = k+1; i <= n; i++) {
		if (A[i-1] < heap[1]) {
			heap[1] = A[i-1];
			max_heapify(1,k,heap);
		}
	}
	return heap[1];
}

int main()
{
	int a, d, P[11], Q[11], x, y, i;
	scanf("%d %d", &a, &d);
	while (a != 0 && d != 0) {
		for (i = 0; i < a; i++) {
			scanf("%d", &P[i]);
		}
		for (i = 0; i < d; i++) {
			scanf("%d", &Q[i]);
		}
		x = kth_smallest(P,a,1);
		y = kth_smallest(Q,d,2);
		if (x < y) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
		scanf("%d %d", &a, &d);
	}
	return 0;
}
