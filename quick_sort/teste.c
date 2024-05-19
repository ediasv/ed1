#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  int a [50];
  srand(time(NULL));
  int i, right = 13, left = 5;
  for (i = 0; i < 50 ; i++) {
    a[i] = (rand() % (right - left + 1)) + left;
    printf("%d\n", a[i]);
  }

  return 0;
}
