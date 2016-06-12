#include <stdio.h>
#include <string.h>

int myatoi(char s[])
{
    int i, r = 0;
    for (i = 0; s[i] != '\0'; i++) {
    	r = r*10 + s[i] - '0';
	}
    return r;
}

char* myitoa(int n, char s[], int b)
{
    int i = 0, j;
    int v = 0;
    if (n == 0)
    {
        s[i++] = '0';
        s[i] = '\0';
        return s;
    }
    while (n != 0)
    {
        int r = n % b;
        s[i] = (r > 9)? (r-10) + 'a' : r + '0';
        i++;
        n = n/b;
    }
    s[i] = '\0';
    char s1[i];
    for (j = i-1; j >= 0; j--) {
    	s1[(i-1) - j] = s[j];
	}
	s1[i] = '\0';
	for (j = 0; j < i; j++) {
    	s[j] = s1[j];
	}
	s[j] = '\0';
    return s;
}

int main()
{
	int t, i, j, k, z, flag, r, l, d, l1, l2, l3, c;
	char s1[15], s2[15], s3[15], s[15], ws[15],a,b;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		flag = 0;
		scanf("%s %c %s %c %s", s1, &a, s2, &b, s3);
		l1 = strlen(s1);
		l2 = strlen(s2);
		l3 = strlen(s3);
		z = 0;
		while (s1[z] != '\0' && s2[z] != '\0' && s3[z] != '\0') {
			if (s1[z] == 'm') {
				flag = 1;
				break;
			} else if (s2[z] == 'm') {
				flag = 2;
				break;
			} else if (s3[z] == 'm') {
				flag = 3;
				break;
			}
			z++;
		}
		if (flag == 1) {
			strcpy(ws,s1);
			l = l1 - 7;
			r = myatoi(s3) - myatoi(s2);
		} else if (flag == 2) {
			strcpy(ws,s2);
			l = l2 - 7;
			r = myatoi(s3) - myatoi(s1);
		} else {
			strcpy(ws,s3);
			l = l3 - 7;
			r = myatoi(s1) + myatoi(s2);
		}
		myitoa(r, s, 10);
		d = strlen(s) - l;
		char ns[strlen(s)];
		c = 0;
		for (j = 0; j < strlen(s); j++) {
			if (ws[j] != 'm') {
				ns[c] = ws[j];
				c++;
			} else {
				for (k = j; k < d+j; k++) {
					ns[c] = s[k];
					c++;
				}
				for (k = j+7; ws[k] != '\0'; k++) {
					ns[c] = ws[k];
					c++;
				}
				break;
			}
		}
		ns[c] = '\0';
		if (flag == 1) {
			printf("%s + %s = %s\n", ns, s2, s3);
		} else if (flag == 2) {
			printf("%s + %s = %s\n",s1, ns, s3 );
		} else {
			printf("%s + %s = %s\n", s1, s2, ns);
		}
	}
}
