#include <stdio.h>
#include <string.h>

int factorial(int n) {
    int rst;
    printf("%d%c", n, 10);
    if (n == 0)
        rst = 1;
    else
        rst = n;
    if (n != 1 && n != 0)
        rst = n * factorial(n-1);
    return rst;
}

int main() {
    int input = 4;
    int a = factorial(input);
    printf("INPUT: %d%cRESULT: %d", input, 10, a);
    return 0;
}
