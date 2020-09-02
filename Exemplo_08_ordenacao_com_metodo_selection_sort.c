/*
 Algorítmo de ordenação por seleção (Selection Sort).
*/
#include  <stdio.h>

#include <locale.h>

int main(void)
{
   setlocale(LC_ALL,"Portuguese");

   int SIZE = 20;// Define uma variável com o tamanho do array elementos.

   // Array de numeros inteiros desordenados para aplicação do método de ordenação.
   int elementos[] = {345,34,21,78,3,4,2,90,11,14,0,1,15,19,87,25,34,37,52,8};

   int i,j,k;// contador do laço for e variável auxíliar k.

   printf("\t\tArray de elementos antes da aplicação do método de ordenação selection sort\n\n");
   for(i = 0; i < SIZE; i++){
       printf("  %d  ",elementos[i]);
   }

   printf("\n\n");
   printf("\t\tArray de elementos depois da aplicação do método de ordenação selection sort\n\n");

   for(i = 0; i < ( SIZE-1 ) ; i++){// Laço externo controla o indíce inicial.
     int menores = i;// Define o elemento atual da iteração como o menor.
       for(j = (i+1); j < SIZE; j++){// laço interno percorre o vetor.
         if(elementos[j] < elementos[menores])
              menores = j;
         }
         if(elementos[i] != elementos[menores]){
              k = elementos[i];
              elementos[i] = elementos[menores];
              elementos[menores] = k;
           }
     }
          for(i = 0; i < SIZE; i++){
              printf("  %d  ",elementos[i]);
     }

}
