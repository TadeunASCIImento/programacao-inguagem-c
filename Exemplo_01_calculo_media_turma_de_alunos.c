#include <stdio.h>
#include <locale.h>

int main(void){
	
	setlocale(LC_ALL,"Portuguese");
	
	int contador = 0;
	float nota ;
	float total = 0;
	float media;
	
	printf("Entre com a nota, -1 para finalizar\n");
		 scanf("%f",&nota);
		
		while(nota != -1){
		 total += nota;
		 contador++;
			
	printf("Entre com a nota, -1 para finalizar\n");
		 scanf("%f",&nota);
			
	}
	
	if(contador != 0){
		 media = (total / contador);
	 	 printf("A média da turma é: %.2f",media);
	}else{
		printf("Não foram informadas notas!\n");
	}
	
	
}
