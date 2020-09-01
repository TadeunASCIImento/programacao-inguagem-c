/*
 Pesquisa Linear de um elemento em um array.
 */
#include  <stdio.h>

#include <locale.h>

#define SIZE 200

int buscaLinear(const int elementos[], int elemento, int size); // Declara a função de busca linear.

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  int elementos[SIZE]; // Define um array de 200 elementos inteiros.
  int elemento; // Define o elemento que será pesquisado no array.
  int chave; // Define o local do elemento no array.
  int i; //contador

  // populando o array de dados com 200 números inteiros.
  for (i = 1; i <= SIZE; i++) {
    elementos[i] = 2 * i;
    printf("\t%d", elementos[i], i);
    if (elementos[i] % 30 == 0)
      printf("\n");

  }

  char message[] = {
    "não foi encontrado no array"
  }; //configura mensagem de elemento não encontrado

  printf("\n\nEntre com um número inteiro para pesquisa no array elementos:\n");
  scanf("%d", & chave); // captura a entrada do elemento pelo teclado.
  elemento = buscaLinear(elementos, chave, SIZE);
  if (elemento != -1) {
    printf("Número encontrado na posição %d", elemento);
  } else {
    printf("O número %d  %s", chave, message);
  }

}

// Define a função de busca linear pelo elemento no array de números inteiros
int buscaLinear(const elementos[], int elemento, int size) {
  int contador;
  for (contador = 0; contador < size; contador++) {
    if (elementos[contador] == elemento) {
      return contador;
    }
  }
  return -1;
}
