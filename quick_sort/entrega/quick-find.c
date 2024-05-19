#include "utils.h"

/* */
int partition (int A[], int left, int right) {
  /*Identico ao partition original.*/	
  int pivot = A[right];
  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (A[j] <= pivot) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i+1, right);
  return i+1;
}

/* */
int random_partition (int A[], int left, int right) {
  /*Terminar*/
  int pivot = (rand() % (right - left + 1)) + left;
  swap(A, right, pivot);
  /*...*/	
  return partition (A, left, right);
}

void quick_find (int *A, int left, int right, int k) {
  /*Terminar*/	
  if (left < right) {
    int pivot = random_partition(A, left, right);
    if (pivot < k) {
      quick_find(A, pivot+1, right, k);
    } else if (pivot > k) {
      quick_find(A, left, pivot-1, k);
    }
  }
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  quick_find (A, 0, n-1, 8);
  print (A, n, "Partial sorted");
  return 0;
}
