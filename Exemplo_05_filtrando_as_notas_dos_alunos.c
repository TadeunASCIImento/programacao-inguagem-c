#include <stdio.h>

#include <locale.h>

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int nota;
  int contadorA = 0;
  int contadorB = 0;
  int contadorC = 0;
  int contadorD = 0;
  int contadorE = 0;
  int contadorF = 0;

  printf("Informe a nota em letra.\n");
  printf("Exemplo: a,b,c,d,e,f ou EOF para encerrar.\n\n");
  printf("Obs: para inserir EOF no windows digite ctrl+z depois enter.\n");
  printf("Obs: para inserir EOF em sistemas Linux/UNIX/Mac OS X enter depois ctrl+d.\n");

  while ((nota = getchar()) != EOF) {
    switch (nota) {
    case 'A':
    case 'a':
      ++contadorA;
      break;

    case 'B':
    case 'b':
      ++contadorB;
      break;
    case 'C':
    case 'c':
      ++contadorC;
      break;
    case 'D':
    case 'd':
      ++contadorD;
      break;
    case 'E':
    case 'e':
      ++contadorE;
      break;
    case 'F':
    case 'f':
      ++contadorF;
      break;

    case '\n':
    case '\t':
    case ' ':
      break;

    default:
      printf("Entrada invalida!\n");
      printf("Tente novamete:\n");
      break;

    }
  }

  printf("\nTotalizando as notas:\n");
  printf("\nA: %d", contadorA);
  printf("\nB: %d", contadorB);
  printf("\nC: %d", contadorC);
  printf("\nD: %d", contadorD);
  printf("\nE: %d", contadorE);
  printf("\nF: %d", contadorF);
  return 0;

}
