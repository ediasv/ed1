#include "stack.h"

int parser(char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if (c[i] == ']' || c[i] == ')') {
      if (empty(s) || get_peek(s) != '(' || get_peek(s) != '[')
        return 0;
      else if (get_peek(s) != '(' || get_peek(s) != '[')
        return 0;
      else
        pop(s);
    } else {
      push(s, c[i]);
    }
    /* ============================ */
    i++;
  }
  return 1;
}

int main() {
  char *c = "( ( ) [ ( ) ] )";
  // char *c = "( [ ) ]";
  // char *c = "( ) [ ]";
  // char *c = "( [ ]";
  // char *c = ") (";
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}
