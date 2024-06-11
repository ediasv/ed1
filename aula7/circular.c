#include "list.h"

#define TRUE 1
#define FALSE 0
#define UNDEF -1

List *create_circular(List *head) {
  List *tmp = head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = head;
  head->prev = tmp;
  return head;
}

int is_circular(List *l) {
  int circular = UNDEF;
  List *tmp = l;

  while (circular == UNDEF) {
    if (tmp->next == l || tmp->prev == l)
      circular = TRUE;
    if (tmp->next == NULL || tmp->prev == NULL)
      circular = FALSE;
    if (circular == UNDEF)
      tmp = tmp->next;
  }

  if (circular)
    return TRUE;
  return FALSE;
}

int main() {
  int i;
  int n = 4;
  List *l = create();
  for (i = n; i >= 0; i--) {
    l = insert_front(l, i);
  }
  print(l);
  create_circular(l);
  printf("circular: %d\n", is_circular(l));
  destroy(l);
  return 0;
}
