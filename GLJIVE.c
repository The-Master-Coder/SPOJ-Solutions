#include <stdio.h>

int main()
{
	int i, A[10], sum = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &A[i]);
		sum = sum + A[i];
		if (sum == 100) {
			break;
		} else if (sum > 100) {
			if (sum-100 == 100-(sum-A[i])) {
				break;
			} else if (sum-100 > 100-(sum-A[i])) {
				sum = sum - A[i];
				break;
			}
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}
