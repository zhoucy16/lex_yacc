#include <stdio.h>
#include <string.h>

int main() {

	char text[] = "ShanghaiZiLaiShuiuhSiaLiZiahgnahS";
	char True[] = "True";
	char False[] = "False";

	int i;
	int l = strlen(text);
	int lh = l / 2;
	int rst = 1;
	for (i = 0; i < lh; i += 1) {
		if (text[i] != text[l-1-i]) {
			rst = 0;
			break;
		}
	}

	if (rst == 1) {
		printf("True");
	} else {
		printf("False");
	}
	return 0;
}
