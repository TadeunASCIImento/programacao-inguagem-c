/*
  Atividade desenvolvida para disciplina de Estruturas de dados.

  Algoritmos de ordenação usando ponteiros.

  Autor: Tadeu do Nascimento - RA:2217202013  - Semestre: 7° - Período: Noturno - Santo Amaro Turma: 29 - Sala: 304.

*/

#include  <stdio.h>

#include <locale.h>

// define a struct pessoa.
struct pessoa {
  char nome[50];
  int idade;
  char sexo[1];
};

// protótipos das funções de ordenação.
void bubbleSortStruct(struct pessoa * ptrUsers[], int size);
void selectionSortStruct(struct pessoa * ptrUsers[], int size);
void insertionSortStruct(struct pessoa * ptrUsers[], int size);
void quickSortVetor(int * ptrVetor, int size, int inicio, int fim);
void quickSortStruct(struct pessoa * ptrUsers[], int size, int inicio, int fim);

// protótipos das funções de busca.
void buscaLinear(int * ptrVetor, int * ptrElemento);
int buscaBinaria(int * ptrVetor, int * ptrElemento);

// protótipos das funções auxíliares.
void exibirArrayOrdenado(int vetor[], int tamanho);

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  const int SIZE = 6;
  struct pessoa users[SIZE], * ptrUsers[SIZE];

  // popula a struct usuarios a partir da entrada do teclado.
  int cont;
  printf("Entre com os dados da estrutura.\n");
  for (cont = 0; cont < SIZE; cont++) {
    ptrUsers[cont] = & users[cont];
    printf("nome:");
    scanf("%s", & ptrUsers[cont] -> nome);
    printf("idade:");
    scanf("%d", & ptrUsers[cont] -> idade);
    printf("sexo:");
    scanf("%s", & ptrUsers[cont] -> sexo);
  }

  // ordena a struct pela idade.
  printf("Ordenação  com o  método  Bubble Sort\n");
  bubbleSortStruct(ptrUsers, SIZE);

  printf("Ordenação com o método Selection Sort\n");
  selectionSortStruct(ptrUsers, SIZE);

  printf("Ordenação com o método Insertion Sort\n");
  insertionSortStruct(ptrUsers, SIZE);

  printf("Ordenação com  o  método  Quick  Sort\n");
  int inicio = 0,fim = SIZE -1;
  quickSortStruct(ptrUsers, SIZE, inicio, fim);

  // vetor original.
  int vetor[10] = {19,12,23,56,78,234,90,34,38,52};
  int * ptrVetor = vetor;
  int elemento;
  printf("Vetor original:");
  exibirArrayOrdenado(vetor, 10);

  // busca linear no vetor
  printf("Informe o elemento para busca no vetor?");
  scanf("%d", &elemento);
  int *ptrElemento = elemento;
  buscaLinear(ptrVetor, ptrElemento);

  // ordenando o vetor com quickSort e ponteiros.
  printf("\nOrdenado com quick sort e  ponteiros: ");
  quickSortVetor(ptrVetor, 10, 0, 9);
  exibirArrayOrdenado(vetor, 10);

  // realiza a busca binária.
  printf("Informe o elemento para busca?");
  scanf("%d", & ptrElemento);
  int result = buscaBinaria(ptrVetor, ptrElemento);
  if (result == -1) {
    printf("%d não encontrado no vetor.", ptrElemento);
  } else {
    printf("%d encontrado no vetor na posição %d.", ptrElemento, result);
  }

}
// Quick sort ordena a struct .
void quickSortStruct(struct pessoa * ptrUsers[], int size, int inicio, int fim) {
  int i, j, aux;
  i = inicio;
  j = fim - 1;
  struct pessoa * pivo;
  struct pessoa * userTemp;
  pivo = ptrUsers[(inicio + fim) / 2];
  while (i <= j) {
    while (ptrUsers[i] -> idade < pivo -> idade) i++;
    while (ptrUsers[j] -> idade > pivo -> idade) j--;
    if (i <= j) {
      userTemp = ptrUsers[i];
      ptrUsers[i] = ptrUsers[j];
      ptrUsers[j] = userTemp;
      i++;
      j--;
    }
  }
  if (j > inicio) {
    quickSortStruct(ptrUsers, size, inicio, j + 1);
  } else if (i < fim) {
    quickSortStruct(ptrUsers, size, i, fim);
  } else {

    for (i = 0; i < size; i++) {
      printf("Usuário %s ", ptrUsers[i] -> nome);
      printf("idade %d ", ptrUsers[i] -> idade);
      printf("Sexo %s \n", ptrUsers[i] -> sexo);
    }
  }
  printf("\n");
}
// Busca binária.
int buscaBinaria(int * ptrVetor, int * ptrElemento) {
  int inf = 0;
  int sup = 9;
  int meio;
  while (inf <= sup) {
    meio = (int)(inf + sup) / 2;
    if (ptrElemento == ptrVetor[meio])
      return meio; // encontrado
    if (ptrElemento > ptrVetor[meio])
      sup = meio - 1;
    else
      inf = meio + 1;
  }
  return -1; // não encontrado
}
// Bubble Sort ordena a struct .
void bubbleSortStruct(struct pessoa * ptrUsers[], int size) {
  int i, it, j, m;
  struct pessoa * userTemp;
  for (it = 0; it < size - 1; it++) {
    for (j = 0; j < size - it - 1; j++) {
      if (ptrUsers[j] -> idade > ptrUsers[j + 1] -> idade) {
        userTemp = ptrUsers[j];
        ptrUsers[j] = ptrUsers[j + 1];
        ptrUsers[j + 1] = userTemp;
      }
    }
  }
  for (i = 0; i < size; i++) {
    printf("Usuário: %s ", ptrUsers[i] -> nome);
    printf(" idade %d ", ptrUsers[i] -> idade);
    printf("Sexo %s \n", ptrUsers[i] -> sexo);
  }
  printf("\n");
}
// Selection Sort ordena a struct .
void selectionSortStruct(struct pessoa * ptrUsers[], int size) {
  int it, i, posMenorInicial, posMenor = 0;
  struct pessoa * userTemp;
  for (it = 0; it < size - 1; it++) {
    int posMenorInicial = it;
    for (i = posMenorInicial + 1; i < size; i++) {
      if (ptrUsers[i] -> idade > ptrUsers[posMenor] -> idade) {
        posMenor = i;
      }
    }
    if (ptrUsers[posMenor] -> idade < ptrUsers[posMenorInicial] -> idade) {
      userTemp = ptrUsers[posMenorInicial];
      ptrUsers[posMenorInicial] = ptrUsers[posMenor];
      ptrUsers[posMenor] = userTemp;
    }
  }
  for (i = 0; i < size; i++) {
    printf("Usuário %s ", ptrUsers[i] -> nome);
    printf("idade %d ", ptrUsers[i] -> idade);
    printf("Sexo %s \n", ptrUsers[i] -> sexo);
  }
  printf("\n");
}
// Insertion sort ordena a struct .
void insertionSortStruct(struct pessoa * ptrUsers[], int size) {
  int it, j, i;
  struct pessoa * userTemp;
  for (it = 1; it < size; it++) {
    userTemp = ptrUsers[it];
    for (j = it - 1;
      (j >= 0) && ptrUsers[j] -> idade > userTemp -> idade; j--) {
      ptrUsers[j + 1] = ptrUsers[j];
    }
    ptrUsers[j + 1] = userTemp;
  }
  for (i = 0; i < size; i++) {
    printf("Usuário %s ", ptrUsers[i] -> nome);
    printf("idade %d ", ptrUsers[i] -> idade);
    printf("Sexo %s \n", ptrUsers[i] -> sexo);
  }
  printf("\n");
}
// Quick sort rdena o vetor de inteiros
void quickSortVetor(int * ptrVetor, int tamanho, int inicio, int fim) {
  int i, j, pivo, aux;
  i = inicio;
  j = fim - 1;
  int size = tamanho;
  pivo = (int) ptrVetor[(inicio + fim) / 2];
  while (i <= j) {
    while (ptrVetor[i] > pivo) i++;
    while (ptrVetor[j] < pivo) j--;
    if (i <= j) {
      aux = ptrVetor[i];
      ptrVetor[i] = ptrVetor[j];
      ptrVetor[j] = aux;
      i++;
      j--;
    }
  }
  if (j > inicio) {
    quickSortVetor(ptrVetor, size, inicio, j + 1);
  }
  if (i < fim) {
    quickSortVetor(ptrVetor, size, i, fim);
  }

}
// Busca linear.
void buscaLinear(int * ptrVetor, int * ptrElemento) {
  int i;
  int existe = 0;
  for (i = 0; i < 10; i++) {
    if (ptrVetor[i] == ptrElemento)
      printf("%d enecontrado na posição %d\n\n", ptrElemento, i);
  }
}
//Exibi o array ordenado
void exibirArrayOrdenado(int vetor[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf(" %d", vetor[i]);
  }
  printf("\n");
}
