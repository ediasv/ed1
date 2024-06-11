#ifndef _list_h_
#define _list_h_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -INT_MAX
#define TRUE 1
#define FALSE 0

/*Structure*/
typedef struct node {
  int data;
  struct node *next;
} Node, List;

/*Interface:*/
List *create();
void print(List *l);
void destroy(List *l);
List *insert_back(List *l, int k);
List *insert_front(List *l, int k);
List *removek(List *l, int k);

#endif
