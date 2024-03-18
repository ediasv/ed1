#include "queue.h"
#include <time.h>

#define ROLAGENS 6

void jackpot(int n, int r) {
  Queue **carreteis;
  Queue *carr[n];
  int i, j, elem, venceu;

  // Criando (e preenchendo) n carreteis de (r + 1) posicoes
  carreteis = (Queue **)malloc(sizeof(Queue *) * n);
  for (i = 0; i < n; i++) {
    carreteis[i] = create(r + 1);

    elem = rand() % 10; // primeiro elemento é gerado aleatóriamente

    for (j = 0; j < r; j++) {
      enqueue(carreteis[i], elem);
      if (elem < 9)
        elem++;
      else
        elem = 0;
    }
  }

  for (i = 0; i < ROLAGENS; i++) { // efeito de caça níqueis
    for (j = 0; j < n; j++) {
      elem = dequeue(carreteis[j]);
      enqueue(carreteis[j], elem);
      printf("%d ", elem);
    }
    printf("\n");
  }

  venceu = front(carreteis[0]);
  for (i = 1; i < n; i++) {
    if (venceu != front(carreteis[i])) {
      venceu = -1;
      break;
    }
  }

  if (venceu != -1)
    printf("VOCE VENCEU!\n");

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
