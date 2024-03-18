#include "stack.h"

int main() {
  int tam = 6;
  Stack *s = create(tam);

  srand(time(NULL));

  int i;
  for (i = 0; i < tam; i++) {
    push(s, rand() % 10);
  }
  print(s);

  /*TERMINAR*/
  Stack *aux = create(tam);
  while (!empty(s)) {
    if (get_peek(s) % 2)
      push(aux, pop(s));
    else
      pop(s);
  }

  while (!empty(aux))
    push(s, pop(aux));

  print(s);

  destroy(aux);
  destroy(s);
}
