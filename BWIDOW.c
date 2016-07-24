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
	int t, i, j, n, a, b, i1, i2;
	int r[1000], R[1000];
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		a = b = -1;
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d %d", &r[j], &R[j]);
			if (r[j] > a) {
				a = r[j];
				i1 = j;
			}
			if (R[j] > b) {
				b = R[j];
				i2 = j;
			}
		}
		if (i1 == i2) {
			if (kth_smallest(R,n,n-1) < a) {
				printf("%d\n", i1+1);
			} else {
				printf("-1\n");
			}
		} else {
			if (b < a) {
				printf("%d\n", i1+1);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
