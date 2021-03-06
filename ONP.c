#include<stdio.h>
#include<string.h>

int is_opening_parentheses(char c)
{
	if (c == '(') {
		return 1;
	} else {
		return 0;
	}
}

int is_closing_parentheses(char c)
{
	if (c == ')') {
		return 1;
	} else {
		return 0;
	}
	
}

int is_alphabet(char c)
{
	if (c >= 'a' && c <= 'z') {
		return 1;
	} else {
		return 0;
	}
}

int is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
		return 1;
	} else {
		return 0;
	}
}

void push(char item,char *ptr,int *top,int l)
{
	if (*top == (l - 1)) {
		printf("Stack Overflow\n\n");
		return;
	}	
	*top = *top + 1;
	ptr[*top] = item;
	return;
}

void pop(int *top)
{
	if (*top == -1) {
		printf("Stack Underflow\n\n");
		return;
	} else {
		*top = *top - 1;
		return;
	}
}

int is_empty(int *head)
{
	if (*head == -1) {
		return 1;
	} else {
		return 0;
	}
}

char* infix_to_postfix(char e[], int l, char r[])
{
	char stack[l];
	int head = -1, i, c = 0, j = 0;
	for(i = 0; i < l; i++) {
		if (is_alphabet(e[i])) {
			r[j] = e[i];
			j++;
			c++;
		} else if (is_operator(e[i])) {
			if (e[i] == '+') {
				if (stack[head] == '+' || is_empty(&head) || is_opening_parentheses(stack[head])) {
						push(e[i],stack,&head,l);
				} else {
					while (!is_empty(&head) && !is_opening_parentheses(stack[head])) {
						r[j] = stack[head];
						j++;
						c++;
						pop(&head);
					}
					push(e[i],stack,&head,l);
				}	
			}
			if (e[i] == '-') {
				if (stack[head] == '+' || stack[head] == '-' || is_empty(&head) || is_opening_parentheses(stack[head])) {
					push(e[i],stack,&head,l);
				} else {
					while (!is_empty(&head) && !is_opening_parentheses(stack[head])) {
						r[j] = stack[head];
						j++;
						c++;
						pop(&head);
					}
					push(e[i],stack,&head,l);
				}
			}
			if (e[i] == '*') {
				if (stack[head] == '*' ||stack[head] == '+' || stack[head] == '-' || is_empty(&head) || is_opening_parentheses(stack[head])) {
					push(e[i],stack,&head,l);
				} else {
					while (!is_empty(&head) && !is_opening_parentheses(stack[head])) {
						r[j] = stack[head];
						j++;
						c++;
						pop(&head);
					}
					push(e[i],stack,&head,l);
				}
			}
			if (e[i] == '/') {
				if (stack[head] == '/' || stack[head] == '*' ||stack[head] == '+' || stack[head] == '-' || is_empty(&head) || is_opening_parentheses(stack[head])) {
					push(e[i],stack,&head,l);
				} else {
					while (!is_empty(&head) && !is_opening_parentheses(stack[head])) {
						r[j] = stack[head];
						j++;
						c++;
						pop(&head);
					}
					push(e[i],stack,&head,l);
				}
			}
			if (e[i] == '^') {
				push(e[i],stack,&head,l);
			}
		} else if (is_opening_parentheses(e[i])) {
				push(e[i],stack,&head,l);
		} else if (is_closing_parentheses(e[i])) {
				while (!is_empty(&head) && !is_opening_parentheses(stack[head])) {
					r[j] = stack[head];
					j++;
					c++;
					pop(&head);
				}
				pop(&head);
			}
	}
	while (!is_empty(&head)) {
		r[j] = stack[head];
		j++;
		c++;
		pop(&head);
	}
	r[c] = '\0';
	return r;
}

int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		char e[1000000];
		scanf("%s", e);
		int l;
		l = strlen(e);
		char r[l];
		printf("%s\n",infix_to_postfix(e,l,r));
	}
	return 0;
}
