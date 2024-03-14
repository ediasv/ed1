#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jackpot(int n, int r) {
  Queue **carreteis;
  int i, j;
  int elem;

  carreteis = (Queue **)malloc(sizeof(Queue *) * n);
  for (i = 0; i < n; i++) {
    carreteis[i] = create(r + 1);
    elem = rand() % 10;
    while (!full(carreteis[i])) {
      enqueue(carreteis[i], elem);
      if (elem < 9)
        elem++;
      else
        elem = 0;
    }
    // print(carreteis[i]);
  }

  for (i = 0; i < n; i++) {
    destroy(carreteis[i]);
  }
  free(carreteis);
}

int main() {
  srand(time(NULL));
  int n = 3;  /*número de carretéis*/
  int r = 10; /*sequência de números em cada carretel*/
  jackpot(n, r);

  return 0;
}
