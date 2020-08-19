#include <stdio.h>

#include <math.h>

#include <locale.h>

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  double valor;
  double principal = 2000.0;
  double taxa = .05;
  int ano;

  printf("%4s%21s\n", "Ano", "Saldo da conta");
  for (ano = 1; ano <= 10; ano++) {
    valor = principal * pow(1.0 + taxa, ano);
    printf("%4d%21.2f\n", ano, valor);
  }
  return 0;
}
