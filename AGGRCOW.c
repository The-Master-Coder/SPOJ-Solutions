#include <stdio.h>
int t, i, j, n, c, s, e, m;
int A[100001];

void merge(int left[],int l,int right[],int r,int A[])
{
	int i, j, k;
	i = j = k = 0;
	while (i < l && j < r) {
		if (left[i] <= right[j]) {
			A[k] = left[i];
			i++;
		} else {
			A[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < l) {
		A[k] = left[i];
		i++;
		k++;
	}
	while (j < r) {
		A[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int A[], int n)
{
	int i, j, mid;
	if (n < 2) {
		return;
	}
	mid = n / 2;
	int left[mid];
	int right[n - mid];
	for(i = 0; i < mid; i++) {
		left[i] = A[i];
	}
	for(i = mid; i < n; i++) {
		right[i - mid] = A[i];
	}
	merge_sort(left,mid);
	merge_sort(right,n - mid);
	merge(left,mid,right,n-mid,A);
}


int is_valid(int x)
{
  int cp = 1,le = A[0], i;
  for (i = 1; i < n; i++) {
    if (A[i] - le >= x) {
      cp++;
	  if(cp == c) {
	  	return 1;
	  }
      le = A[i];
    }
  }
  return 0;
}

int main()
{
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &c);
		for (j = 0; j < n; j++) {
			scanf("%d", &A[j]);
		}
		merge_sort(A,n);
		s = 0;
		e = A[n-1];
		while (s <= e) {
  			m = (s+e) >> 1;
  			if (is_valid(m)) {
  				s = m+1;
			} else {
				e = m-1;
			}
		}
		printf("%d\n", s-1);
	}
	return 0;
}
