#include "list.h"
#include <stdlib.h>

/* */
List *insert_back(List *l, int k) {
  if (l == NULL) {
    l = (Node *)malloc(sizeof(Node));
    l->data = k;
    l->next = NULL;
  } else {
    l->next = insert_back(l->next, k);
  }
  return l;
}

/* */
List *removek(List *l, int k) {
  List *current = l, *previous = NULL;
  while ((current != NULL) && (current->data != k)) {
    previous = current;
    current = current->next;
  }
  if (current == NULL)
    return l; // nao achou k
  if (previous == NULL)
    l = current->next; // k esta na primeira posicao
  else
    previous->next = current->next;
  free(current);
  return l;
}

/* */
void print(List *l) {
  if (l != NULL) {
    printf("%d ", l->data);
    print(l->next);
  }
}

/* */
void destroy(List *l) { /*Terminar*/
  if (l != NULL) {
    List *tmp;
    while (l->next != NULL) {
      tmp = l;
      l = l->next;
      free(tmp);
    }
    free(l);
  }
}
