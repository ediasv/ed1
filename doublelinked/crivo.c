#include "list.h"
#include <math.h>

void crivo(int n) {
  int i, sq = sqrt(n);
  List *l = create();
  /*Terminar!*/
  List *tmp = l;
  for (i = 0; i < sq; i++) {
  }
  destroy(l);
}

int main() {
  int n = 30;
  crivo(n);
  return 0;
}
