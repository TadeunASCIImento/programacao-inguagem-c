#include <stdio.h>

#include  <locale.h>

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  int aprovados = 0;
  int reprovados = 0;
  int aluno = 1;
  int resultado;

  while (aluno <= 10) {
    printf("Entre com o resultado");
    printf("( 1-Aprovado  2-Reprovado )\n");
    scanf("%d", & resultado);
    if (resultado == 1) {
      aprovados++;
    } else {
      reprovados++;
    }
    aluno++;
  }
  printf("Alunos aprovados: %d\n", aprovados);
  printf("Alunos reprovados: %d\n", reprovados);

  if (aprovados > 7) {
    printf("Bonûs ao Professor.\n");
  }
  return 0;

}
