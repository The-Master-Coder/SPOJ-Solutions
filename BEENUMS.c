#include <stdio.h>

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
		return binary_search(A,start,end,value);
	} else {
		end = mid - 1;
		return binary_search(A,start,end,value);
	}
}

int main()
{
	int A[18260], i = 0, t = 1, n;
	while (t <= 1000000000) {
		A[i] = t;
		t = t + 6*(i+1);
		i++;
	}
	scanf("%d", &n);
	while (n != -1) {
		if (binary_search(A,0,18256,n)) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
		scanf("%d", &n);
	}
	return 0;
}
