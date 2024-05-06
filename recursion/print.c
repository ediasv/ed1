#include "list.h"

void print_reverse(List *l) {
  if (l != NULL) {
    print_reverse(l->next);
    printf("%d ", l->data);
  }
}

int main() {
  List *a = create();
  int i;
  for (i = 0; i < 5; i++)
    a = insert_back(a, i);

  print(a);
  printf("\n");

  print_reverse(a);

  return 0;
}
