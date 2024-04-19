#include "list.h"
#include <math.h>

List *remove_multiplos(List *l, int limite) {
  int i = 2;
  List *current = l, *previous = l;
  while (i < limite) {
    current while (current->next != NULL) {
      if (current->data % i == 0)
        remove_queue(l, current->data);
    }
    previous = previous->next;
  }
  return l;
}

void crivo(int n) {
  int i, sq = sqrt(n);
  List *l = create();
  /*Terminar!*/
  for (i = 2; i <= n; i++)
    insert_back(l, i);
  l = remove_multiplos(l, sq);
  destroy(l);
}

int main() {
  int n = 30;
  crivo(n);
  return 0;
}
