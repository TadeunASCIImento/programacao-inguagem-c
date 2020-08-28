#include <stdio.h>

#include <locale.h>

#include <stdlib.h>

// Ordenação usando o metodo bolha.
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	const int TAM = 10;
	int elementos[] = {12 ,45 ,6 ,8 ,2 ,9 ,3 ,1 ,10 ,90} ,i ,j ,k,m;

	printf("Elementos antes da aplicação do método de ordenação.\n");
	  for(i = 0; i < TAM; i++){
	  	printf(" %d",elementos[i]);
		}

	printf("\nElementos depois da aplicação do método de ordenação.\n");
		for(m = 0; m < TAM; m++){
		     for(i = 0; i< TAM-1; i++){//Quantidade de vezes necessárias.
		         for(j = 0; j< TAM-1; j++){//cada elemento do array.
		            //verifica se o elemento adjacente é maior.
			    if(elementos[j] > elementos[j+1]){
			    //variável auxíliar para troca.
			    k = elementos[j];
			    elementos[j] = elementos[j+1];//troca
			    //posiciona maior, mais ao fim.
			    elementos[j+1] = k;
		            }
	                 }
                     }      printf(" %d",elementos[m]) 
		}
} 
