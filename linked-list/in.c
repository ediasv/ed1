#include "list.h"

/* */
int in(List *l, int k) {
  /*Terminar!*/
  if (search(l, k) == NULL)
    return FALSE;
  return TRUE;
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
  printf("Pertence %d = %d?\n", 9, in(l, 9));
  printf("Pertence %d = %d?\n", -1, in(l, -1));
  destroy(l);
  return 0;
}
