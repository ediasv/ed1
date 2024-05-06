#include "list.h"
#include <stdlib.h>

List *copy(List *a) {
  List *b = (List *)malloc(sizeof(List));
  if (a != NULL) {
    b->data = a->data;
    b->next = copy(a->next);
  } else
    b = NULL;

  return b;
}

int main() {
  List *a = create(), *b = create();
  int i;
  for (i = 0; i < 5; i++)
    a = insert_back(a, i);

  print(a);
  printf("\n");

  b = copy(a);

  destroy(a);

  print(b);
  printf("\n");

  return 0;
}
