#include "utils.h"

/* */
int partition (int A[], int left, int right) {
  /*Terminar*/	
  int pivot = A[right];
  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (A[j] < pivot) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i+1, right);
  return i+1;
}

/* */
void quick_sort (int *A, int left, int right) {
  /*Terminar*/	
  if (left < right) {
    int pivot = partition(A, left, right);
    quick_sort(A, left, pivot-1);
    quick_sort(A, pivot+1, right);
  }
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = atoi( argv[1] ); /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = atoi(argv[1]); /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios; t(1000) = 0.00; t(10000) = 0.00; t(100000) = 0.03*/ 
    // A[i] = i; /*ordem crescente t(1000) = 0.01; t(10000) = 0.28; t(100000) = 26.02*/
    // A[i] = n-i; /*ordem descrente t(1000) = 0.01; t(10000) = 0.19; t(100000) = 17.45*/
    // A[i] = 0; /*iguais t(1000) = 0.00; t(10000) = 0.11; t(100000) = 10.16*/
  }  

  start = clock();
  // print (A, n, "Input");
  quick_sort (A, 0, n-1);
  // print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

