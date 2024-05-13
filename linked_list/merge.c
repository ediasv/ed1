#include "list.h"

List *merge(List *A, List *B) {
  /*Terminar*/
  List *tmp = A;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = B;
  return A;
}

/**/
int main() {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2)
    A = insert_front(A, k);
  for (k = 19; k >= 0; k -= 2)
    B = insert_front(B, k);
  print(A);
  print(B);
  List *C = merge(A, B);
  print(C);
  destroy(C);
  return 0;
}
