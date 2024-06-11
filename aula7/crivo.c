#include "list.h"
#include <math.h>
#include <stdlib.h>

List *remove_node(List *node) {
  if (node->next == NULL) {
    node->prev->next = NULL;
    free(node);
    return NULL;
  }
  List *tmp = node->next;
  node->prev->next = tmp;
  tmp->prev = node->prev;
  free(node);
  return tmp;
}

void crivo(int n) {
  int i, sq = sqrt(n);
  List *l = create();
  /*Terminar!*/
  for (i = 2; i <= n; i++)
    l = insert_back(l, i);
  print(l);

  List *tmp;

  for (i = 2; i <= sq; i++) {
    tmp = l;
    while (tmp != NULL) {
      if (!(tmp->data % i) && (tmp->data != i)) {
        tmp = remove_node(tmp);
      } else {
        tmp = tmp->next;
      }
    }
  }

  print(l);
  destroy(l);
}

int main() {
  int n = 30;
  crivo(n);
  return 0;
}
