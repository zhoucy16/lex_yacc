#include <iostream>
#include <cstring>

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
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }

    i = 0;
    j = 0;
    int num = 0;
    while (j < n) {
        while (i > -1 && x[i] != y[j]){
          i = kmpNext[i];
        x}
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
            printf(res[i]);
            printf(comma);
        }
        printf(res[num - 1]);
    }
   return 0;
}
