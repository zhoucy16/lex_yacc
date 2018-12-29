#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;
    int j = -1;
    int kmpNext[100];
    kmpNext[0] = -1;
    char text[] = "runningmann";
    int n = strlen(text);
    char pattern[] = "nn";
    int m = strlen(pattern);
    char noAnswer[] = "False";
    char comma = ',';
    int res[100];

    while (i < m) {
      while (j > -1 && pattern[i] != pattern[j])
         j = kmpNext[j];
      i++;
      j++;
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
      i++;
      j++;
      if (i >= m) {
        res[num] = j - i;
        i = kmpNext[i];
      }
    }
    if(num == 0){
        printf(noAnswer);
    }
    else if (num == 1){
        printf(res[0]);
    }
    else {
        for(i = 0; i < num - 1; i++){
            printf(toString(res[i]));
            printf(comma);
        }
        printf(toString(res[num - 1]));
    }
   return 0;
}
