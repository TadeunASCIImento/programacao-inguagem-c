/* Método de ordenação por inserção ( Insertion Sort).*/
#include  <stdio.h>

#include <locale.h>

int main(void)
{
	  setlocale(LC_ALL,"Portuguese");

		int SIZE = 20;// Define uma variável com o tamanho do array elementos.

		// Array de numeros inteiros desordenados para aplicação do método de ordenação.
		int elementos[] = {345,34,21,78,3,4,2,90,11,14,0,1,15,19,87,25,36,37,52,8};

		int i,j,k,elemento;// contador do laço for e variável auxíliar k.

	  printf("\t\tArray de elementos antes da aplicação do método de ordenação insertion sort\n\n");
	  for(i = 0; i < SIZE; i++){
	  	  printf("  %d  ",elementos[i]);
		}

		// Ordena os elementos usando o metodo insertion sort.
		for(i = 1; i < SIZE; i++){
			  elemento = elementos[i];
			 for(j = i-1; (j >= 0) && elementos[j] > elemento; j--){
			 	   elementos[j+1]  = elementos[j];
			 }   elementos[j+1] = elemento;
		}

		printf("\t\tArray de elementos depois da aplicação do método de ordenação insertion sort\n\n");
	       for(i = 0; i < SIZE; i++){
	  	       printf("  %d  ",elementos[i]);
		     }

}
