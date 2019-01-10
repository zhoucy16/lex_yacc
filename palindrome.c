#include <stdio.h>
#include <string.h>


int main() {
	char str[100];
	printf( "请输入一个字符串:");
   	scanf("%s", str);

	int a = 1;
	int i;
	int l = strlen(str);	
	int lh = l / 2;
	int rst = 1;
	for (i = 0; i < lh; i += 1) {
		if (str[i] != str[l-1-i]) {
			rst = 0;
			break;
		}
	}

	if (rst == 1) {
		printf("True %d", 1);
	} else {
		printf("False");
	}
	return 0;
}
