#include <stdio.h>
#include <string.h>

int main() {
	printf( "请输入要计算的四则表达式，请以#作为结尾:");
	char expr[100];
    scanf("%s", expr);
	
	char post[1000];
	char ss[1000];
	char ch;
	int sum;
	int i;
	int t;
	int z;
	int error = 0;
	int top = 0;
	sum = strlen(expr);
	t = 1;
	i = 0;
	ch = expr[i];
	i += 1;
	while (ch != '#') {
		if (ch == '+' || ch == '-') {
			while (top != 0 && ss[top] != '(') {
				post[t] = ss[top];
				top -= 1;
				t += 1;
			}
			top += 1;
			ss[top] = ch;

		} else if (ch == '*' || ch == '/') {
			while (ss[top] == '*'|| ss[top] == '/') {
				post[t] = ss[top];
				top -= 1;
				t += 1;
			}
			top += 1;
			ss[top] = ch;
		} else if (ch == '(') {
			top += 1;
			ss[top] = ch;
		} else if (ch == ')') {
			while (ss[top] != '(') {
				post[t] = ss[top];
				top -= 1;
				t += 1;
			}
			top -= 1;
		} else if (ch == ' ') {
			z = 1;
		} else {
			while (isdigit(ch) || ch == '.') {
				post[t] = ch;
				t += 1;
				ch = expr[i];
				i += 1;
			}
			i -= 1;
			post[t] = ' ';
			t += 1;
		}
		ch = expr[i];
		i += 1;
	} while (top!= 0) {
		post[t] = ss[top];
		t += 1;
		top -= 1;
	}
	post[t] = ' ';
	int newstack[100];
	char newstr[100];
	t=1;
	top=0;
	ch = post[t];
	t=t+1;
	char temp;
	while (ch!= ' ' && error == 0) {
		if (ch == '+') {
			newstack[top-1] = newstack[top-1] + newstack[top];
			top -= 1;
		} else if (ch == '-') {
			newstack[top-1] = newstack[top-1] - newstack[top];
			top -= 1;
		} else if (ch == '*') {
			newstack[top-1] = newstack[top-1] * newstack[top];
			top -= 1;
		} else if(ch == '/') {
			if (newstack[top] != 0)
				newstack[top-1] = newstack[top-1] / newstack[top];
			else
				error = 1;
			top -= 1;
		} else {
			i = 0;
			while (isdigit(ch) || ch == '.') {
				newstr[i] = ch;
				i += 1;
				ch = post[t];
				t += 1;
			}
			temp = 0;
			newstr[i] = temp;
			top += 1;
			newstack[top] = atoi(newstr);
		}
		ch = post[t];
		t += 1;
	}
	
	if(error == 0)
		printf("%d", newstack[top]);
	else
		printf("invalid expression");
	return 0;
}
