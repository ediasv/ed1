#include "list.h"
#include <math.h>

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
    while (tmp->next != NULL) {
      if (tmp != NULL) {
        if (!(tmp->data % i) && (tmp->data != i))
          tmp = remove_queue(tmp, tmp->data);
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
