#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    int j = -1;
    int kmpNext[100];
    kmpNext[0] = -1;
    char text[100];
    printf( "请输入一个字符串:");
    scanf("%s", text);
    int n = strlen(text);
    char pattern[100];
    printf( "请输入一个模式串:");
    scanf("%s", pattern);
    int m = strlen(pattern);
    int res[100];
    
    while (i < m) {
        while (j > -1 && pattern[i] != pattern[j])
            j = kmpNext[j];
        i += 1;
        j += 1;
        if (i >= m || j >= m) {
            break;
        }
        if (pattern[i] == pattern[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
    
    i = 0;
    j = 0;
    int num = 0;
    while (j < n) {
        while (i > -1 && pattern[i] != text[j]){
            i = kmpNext[i];
        }
        i += 1;
        j += 1;
        if (i >= m) {
            res[num] = j - i;
            i = kmpNext[i];
            num += 1;
        }
    }
    if(num == 0){
        printf("False");
    }
    else if (num == 1){
        printf("%d", res[0]);
    }
    else {
        for(i = 0; i < num - 1; i += 1){
            printf("%d", res[i]);
            printf(",");
        }
        printf("%d", res[num - 1]);
    }
    return 0;
}
