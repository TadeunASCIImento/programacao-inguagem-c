/* 
	Atividade desenvolvida para disciplina de Estruturas de dados.	
	
	Métodos de ordenação, Bubble Sort, Selection Sort, Insertition Sort e Quick Sort.
	
	Autor: Tadeu do Nascimento - RA: 2217202013  - Semestre: 7° - Período: Noturno	
	
	Turma: 29 - Sala: 304. 
*/
#include <stdio.h>

#include<locale.h>

#include<stdlib.h>

#include  <time.h>

// funções de ordenação
void bubbleSort(int array[], int tamanho);
void selectionSort(int array[], int tamnaho);
void insertionSort(int array[], int tamanho);
void quickSort(int array[], int tamanho, int inicio, int fim);

//funções auxilíliares
int obterEntradaDoUsuario();
void exibirMenuDeOpcoes();
void exibirArrayDesordenado(int array[], int tamanho);
void ordenarArrayDeInteiros(int opcao, int array[], int tamanho);
void exibirArrayOrdenado(int array[], int tamanho);
void exibirTamanhoDoArray(int tamanho);
void executarBenchmarkDeOrdenacao(int array[], int tamanho);
void finalizar();

// main
int main(void) {
  
	setlocale(LC_ALL, "Portuguese");
  int opcao = 0;
  int tam;
  int array[tam];
  int continueLoop = 0;
  
	do{
	exibirMenuDeOpcoes();
  opcao = obterEntradaDoUsuario();
  if(opcao == 6)break;
	else printf("\nEntre com o tamanho do array: ");
  tam = obterEntradaDoUsuario();
	ordenarArrayDeInteiros(opcao, array, tam);
}while(1);
  printf("\n\t\tFinalizado");
  return 0;
}

// entrada 
int obterEntradaDoUsuario() {
  int opcao;
  scanf("%i", & opcao);
  return opcao;
}

// menu
void exibirMenuDeOpcoes() {
  printf("\nEntre com a opção desejada: ");
  printf("\n(1)Bubble Sort");
  printf("\n(2)Selection Sort");
  printf("\n(3)Insertion Sort");
  printf("\n(4)Quick Sort");
  printf("\n(5)Estatísticas");
  printf("\n(6)Sair\n");
}

// exibir array desordenado
void exibirArrayDesordenado(int array[], int tamanho) {
  int size = tamanho, i;
  printf("Array desordenado:");
  srand(time(NULL));
  for (i = 0; i < size; i++) {
    array[i] = 1 + (rand() % 100);
    printf(" %d", array[i]);
  }
  printf("\n");
}

// opções de ordenação
void ordenarArrayDeInteiros(int opcao, int array[], int tamanho) {

  int i, inicio, fim;
  int size = tamanho;
  inicio = size - size;
  fim = (size - 1);

  switch (opcao) {
  case 1:
  	printf("\n\n\t\tBUBBLE SORT\n\n");
    exibirArrayDesordenado(array, size);
    bubbleSort(array, size);
    exibirTamanhoDoArray(size);
    exibirArrayOrdenado(array, size);
    break;
  case 2:
  	printf("\n\n\t\tSELECTION SORT\n\n"); 
    exibirArrayDesordenado(array, size);
    selectionSort(array, size);
    exibirTamanhoDoArray(size);
    exibirArrayOrdenado(array, size);
    break;
  case 3:
    printf("\n\n\t\tINSERTION SORT\n\n");	
    exibirArrayDesordenado(array, size);
    insertionSort(array, size);
    exibirTamanhoDoArray(size);
    exibirArrayOrdenado(array, size);
    break;
  case 4:
  	printf("\n\n\t\tQUICK SORT\n\n");
    exibirArrayDesordenado(array, size);
    quickSort(array, size, inicio, fim);
    exibirTamanhoDoArray(size);
    exibirArrayOrdenado(array, size);
    break;
  case 5:
  	  printf("\n\n\t\tBENCHMARK\n\n");
    executarBenchmarkDeOrdenacao(array, size);
    break;
  }
}

//exibir array ordenado
void exibirArrayOrdenado(int array[], int size) {
  int i;
  printf("Array ordenado: ");
  for (i = 0; i < size; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

// tamanho do array
void exibirTamanhoDoArray(int size) {
  printf("\nTamanho do array: %i\n", size);
}

// benchmark
void executarBenchmarkDeOrdenacao(int array[], int tamanho) {

  int size = tamanho;
  double tempoBubbleSort, tempoSelectionSort, tempoInsertionSort, tempoQuickSort;
  int inicio, fim;
  inicio = size - size;
  fim = (size - 1);
  
  printf("\n\n\t\tBUBBLE SORT\n\n");
  exibirArrayDesordenado(array, size); 
  clock_t tempo1;
  tempo1 = clock();
  bubbleSort(array, size);
  tempoBubbleSort = (clock() - tempo1) / (double) CLOCKS_PER_SEC;
  exibirArrayOrdenado(array, size);

  printf("\n\n\t\tSELECTION SORT\n\n"); 
	exibirArrayDesordenado(array, size);
  clock_t tempo2;
  tempo2 = clock();
  selectionSort(array, size);
  tempoSelectionSort = (clock() - tempo2) / (double) CLOCKS_PER_SEC;
  exibirArrayOrdenado(array, size);

  printf("\n\n\t\tINSERTION SORT\n\n");
  exibirArrayDesordenado(array, size);
  clock_t tempo3;
  tempo3 = clock();
  insertionSort(array, size);
  tempoInsertionSort = (clock() - tempo3) / (double) CLOCKS_PER_SEC;
  exibirArrayOrdenado(array, size);
 
  printf("\n\n\t\tQUICK SORT\n\n"); 
  exibirArrayDesordenado(array, size);
  printf("\n");
  clock_t tempo4;
  tempo4 = clock();
  quickSort(array, size, inicio, fim);
  tempoQuickSort = (clock() - tempo4) / (double) CLOCKS_PER_SEC;
  exibirArrayOrdenado(array, size);

  printf("\n\nEstatísticas:");
  exibirTamanhoDoArray(size);
  printf("Tempo de execução Bubble Sort :%.6fs", tempoBubbleSort);
  printf("\nTempo de execução Selection Sort :%.6fs", tempoSelectionSort);
  printf("\nTempo de execução Insertion Sort :%.6fs", tempoInsertionSort);
  printf("\nTempo de execução Quick Sort: %.6fs", tempoQuickSort);
  printf("\n");
}

// bubble sort
void bubbleSort(int array[], int tamanho) {

  const int SIZE = tamanho;
  int i, it, j, k, m;
  for (it = 0; it < SIZE - 1; it++) {
    printf("\n( Iteração %i )\n", it + 1);
    printf("------------------\n");

    for (j = 0; j < SIZE - it - 1; j++) {
      if (array[j] < array[j + 1]) {
        k = array[j];
        array[j] = array[j + 1];
        array[j + 1] = k;
      }

      for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
      }
      printf("\n");
    }
  }
}
// selection sort
void selectionSort(int array[], int tamanho) {

  const int SIZE = tamanho;
  int i, it, posMenorInicial, posMenor = 0, temp;
  for (it = 0; it < SIZE - 1; it++) {
    int posMenorInicial = it;
    for (i = posMenorInicial + 1; i < SIZE; i++) {
      if (array[i] > array[posMenor]) {
        posMenor = i;
      }
    }
    if (array[posMenor] > array[posMenorInicial]) {
      temp = array[posMenorInicial];
      array[posMenorInicial] = array[posMenor];
      array[posMenor] = temp;
    }
    printf("\n( Iteração %i )\n", it + 1);
    printf("------------------\n");
    for (i = 0; i < SIZE; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
  }
}
// insertion sort
void insertionSort(int array[], int tamanho) {

  const int SIZE = tamanho;
  int i, it, j, k, elemento;
  for (it = 1; it < SIZE; it++) {
    elemento = array[it];
    for (j = it - 1;
      (j >= 0) && array[j] < elemento; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = elemento;
    printf("\n( Iteração %i )\n", it);
    printf("--------------------\n");
    for (i = 0; i < SIZE; i++) {
      printf("%i ", array[i]);
    }
    printf("\n");
  }
}
// quick sort
void quickSort(int array[], int tamanho, int inicio, int fim){

  int i, j, pivo, aux;
  i = inicio;
  j = fim - 1;
  int size = tamanho;
  pivo = array[(inicio + fim) / 2];

  while (i <= j) {
    while (array[i] > pivo) i++;
    while (array[j] < pivo) j--;
    if (i <= j) {
      aux = array[i];
      array[i] = array[j];
      array[j] = aux;
      i++;
      j--;
    }
 }
  
  if (j > inicio) {
    quickSort(array, size, inicio, j + 1);
  }
  if (i < fim) {
    quickSort(array, size, i, fim);
  }
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
    printf("\n");

}
