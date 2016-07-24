#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char s[], int l) {
	int i;
    for (i = 0; i < l/2; i++) {
        if (s[i] != s[l-i-1]) {
        	return false;
		}
    }
    return true;
}

int main()
{
	int t, i, l;
	char s[10];
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		memset(s,0,10);
		scanf("%s", s);
		l = strlen(s);
		if (is_palindrome(s,l)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
