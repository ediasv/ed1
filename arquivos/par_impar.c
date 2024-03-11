#include "queue.h"
#include <time.h>


int main () {
  int i, n = 10;	
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  i = 0;
  Queue *impar = create(n);
  Queue *par = create(n);

  srand(time(NULL));

  while (i < n) {
    int elem = rand() % 11;
    
    if (elem % 2) { // é impar
      enqueue(impar, elem);
    }
    else {
      enqueue(par, elem);
    }
    i++;
  }
  print(impar);
  print(par);
  destroy (impar);
  destroy (par);

  return 0;
}

