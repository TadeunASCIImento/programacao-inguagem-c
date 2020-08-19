#include <stdio.h>

#include <locale.h>

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int variavel;

  variavel = 5;

  printf("Valor antes do pós-incremento:  %d\n", variavel);
  printf("Valor durante o pós-incremento: %d\n", variavel++);
  printf("Valor depois do pós-incremento: %d\n", variavel);

	printf("\n\n");

	printf("Valor antes do pré-incremento:  %d\n", variavel);
  printf("Valor durante o pré-incremento: %d\n", ++variavel);
  printf("Valor depois do pré-incremento: %d\n", variavel);

  printf("\n\n");

  printf("Valor antes do pós-decremento:  %d\n", variavel);
  printf("Valor durante o pós-decremento: %d\n", variavel--);
  printf("Valor depois do pós-decremento: %d\n", variavel);

  printf("\n\n");

	printf("Valor antes do pré-decremento:  %d\n", variavel);
  printf("Valor durante o pré-decremento: %d\n", --variavel);
  printf("Valor depois do pré-decremento: %d\n", variavel);
  return 0;
}
