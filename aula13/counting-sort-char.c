#include "utils.h"
#include <ctype.h>
#include <stdio.h>

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  for (i = 0; i <= range; i++)
    C[i] = 0;

  char ch;

  do {
    ch = fgetc(f);
    if (isalpha(ch)) {
      total++;
      ch = toupper(ch);
      C[ch - 65]++;
    }
  } while (ch != EOF);

  printf("Letra  Contagem  Frequencia\n");
  for (i = 0; i < 'Z' - 'A'; i++) {
    printf("%5c  %8d  %.4f\n", (i + 'A'), C[i], ((float) C[i])/total);
  }

  /*Imprimir no final desta função as frequências das letras!*/
}

/* */
int main (int argc, char *argv[]) {

  /*if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }*/

  //FILE *f = fopen(argv[1], "r");

  FILE *f = fopen("livro_pt.txt", "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);

  fclose (f);

  return 0;
}

