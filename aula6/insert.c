#include "list.h"

List *insert_sort(List *l, int k) {
  if (l == NULL) {
    l = insert_front(l, k);
  } else {
    if (k < l->data)
      l = insert_front(l, k);
    else
      l->next = insert_sort(l->next, k);
  }
  return l;
}

int main() {
  List *l = create();
  l = insert_sort(l, 9);
  l = insert_sort(l, 0);
  l = insert_sort(l, 4);
  l = insert_sort(l, 2);
  l = insert_sort(l, 7);
  print(l);
  destroy(l);
  return 0;
}
