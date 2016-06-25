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
	int t, i, j, n1, n2;
	int A[100000], B[100000];
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &n1, &n2);
		for (j = 0; j < n1; j++) {
			scanf("%d", &A[j]);
		}
		for (j = 0; j < n2; j++) {
			scanf("%d", &B[j]);
		}
		if (kth_smallest(A,n1,n1) < kth_smallest(B,n2,n2)) {
			printf("MechaGodzilla\n");
		} else {
			printf("Godzilla\n");
		}
	}
	return 0;
}
