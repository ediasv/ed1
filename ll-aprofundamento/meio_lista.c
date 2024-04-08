#include "list.h"

int meio(List *l) {
  /*Terminar*/
  List *tmp = l->next;
  List *tmp2 = l;
  int i = 1;
  while (tmp != NULL) {
    tmp = tmp->next;
    i++;
    if (i % 2 == 0) {
      tmp2 = tmp2->next;
    }
  }
  return tmp2->data;
}

int main() {
  int i;

  List *l0 = create();
  for (i = 0; i < 3; i++)
    l0 = insert(l0, i);
  print(l0);
  printf("Elemento no meio da lista: %d\n", meio(l0));
  destroy(l0);

  List *l1 = create();
  for (i = 0; i < 10; i++)
    l1 = insert(l1, i);
  print(l1);
  printf("Elemento no meio da lista: %d\n", meio(l1));
  destroy(l1);

  List *l2 = create();
  for (i = 0; i < 19; i++)
    l2 = insert(l2, i);
  print(l2);
  printf("Elemento no meio da lista: %d\n", meio(l2));
  destroy(l2);

  return 0;
}
