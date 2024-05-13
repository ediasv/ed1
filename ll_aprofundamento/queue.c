#include "queue.h"

Queue *create() {
  /*Terminar*/
  Queue *head = NULL;
  return head;
}

void destroy(Queue *q) {
  /*Terminar*/
  Queue *current = q;
  Queue *previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
    free(previous);
  }
  free(current);
}

int empty(Queue *q) {
  /*Terminar*/
  return (q == NULL);
}

Queue *enqueue(Queue *q, int elem) {
  /*Terminar*/
  Queue *tmp = (Queue *)malloc(sizeof(Queue));
  tmp->next = NULL;
  tmp->data = elem;
  if (q == NULL)
    return tmp;
  Queue *nxt = q;
  while (q->next != NULL)
    q = q->next;
  q->next = tmp;
  return q;
}

Queue *dequeue(Queue *q) {
  /*Terminar*/
  Queue *tmp = q;
  q = q->next;
  return tmp;
}

int get_front(Queue *q) {
  /*Terminar*/
  if (q == NULL)
    return ERROR;
  return q->data;
}

void print(Queue *q) {
  /*Terminar*/
  Queue *tmp = q;
  while (tmp != NULL)
    printf("%d ", tmp->data);
  printf("\n");
}
