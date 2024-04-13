#include "list.h"

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
  if (l == NULL)
    return l;
  List *current, *previous;
  current = l;
  previous = NULL;
  while (current->next != NULL) {
    if (current->data == k) {
    }
    previous = current;
    current = current->next;
  }
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
}
