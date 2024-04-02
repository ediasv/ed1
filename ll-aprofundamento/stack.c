#include "stack.h"

Stack *create() {
  Stack *s = NULL;
  return s;
}

void destroy(Stack *s) {
  Stack *tmp = s;
  while (s->next != NULL) {
    s = s->next;
    free(tmp);
    tmp = s;
  }
  free(s);
}

Stack *push(Stack *s, int elem) {
  Stack *tmp = (Stack *)malloc(sizeof(Stack));
  tmp->data = elem;
  tmp->next = s;
  return tmp;
}

Stack *pop(Stack *s) {
  Stack *tmp = s;
  s = s->next;
  return tmp;
}

int get_peek(Stack *s) {
  if (empty(s))
    return ERROR;
  return s->data;
}

int empty(Stack *s) { return (s == NULL); }

void print(Stack *s) {
  if (!empty(s)) {
    Stack *tmp = s;
    while (tmp != NULL) {
      printf("%d ", tmp->data);
      tmp = tmp->next;
    }
    printf("\n");
  }
}
