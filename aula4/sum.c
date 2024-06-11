#include "list.h"

/* */
int sum(List *l) {
  List *tmp;
  int sum = 0;
  for (tmp = l; tmp != NULL; tmp = tmp->next) {
    sum += tmp->data;
  }
  return sum;
}

/* */
int main() {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++)
    l = insert_front(l, k);
  for (k = 9; k >= 5; k--)
    l = insert_front(l, k);
  print(l);
  printf("Sum = %d\n", sum(l));
  destroy(l);
  return 0;
}
