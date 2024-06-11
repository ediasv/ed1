#include "list.h"
#include <iso646.h>

List *replicate(List *l, int k) {
  List *tmp = l;
  // cria k-1 elementos
  int i;
  List *new;
  for (i = 0; i < (k - 1); i++) {
    new = (List *)malloc(sizeof(List));
    new->data = tmp->data;
    new->next = tmp->next;
    new->prev = tmp;
    if (tmp->next != NULL)
      tmp->next->prev = new;
    tmp->next = new;
    tmp = new;
  }
  if (tmp->next != NULL)
    tmp = replicate(tmp->next, k);
  return l;
}

int main() {
  int i;
  int k = 3;
  int n = 4;
  List *l = create();
  for (i = n; i >= 1; i--) {
    l = insert_front(l, i);
  }
  print(l);
  l = replicate(l, k);
  print(l);
  destroy(l);
  return 0;
}
