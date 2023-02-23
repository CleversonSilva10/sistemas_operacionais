#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void integrantes_grupo(){
  printf("\n----------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374\n");
  printf("----------------------------------------------\n\n");
};

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	int max, qnt;
	
	while(1){
		
		printf("Por favor, digite o n�mero m�ximo (impar): ");
		scanf("%d", &max);
		if( max%2 != 1){
			printf("Por favor, digite um natural impar !!!\n");
			continue;
		}
		
		qnt = (max/2) + 1; // No caso do C, isso funciona
		
		for(int i = 0; i < qnt; i ++){
			for(int j = 0; j < i; j++){
				printf(" ");
			}
			printf(" ");
			for(int j = i+1; j < max-i+1; j++){
				printf("%d",j);
			}
			printf("\n");
		}
		
		break;
	}
	return 0;
}
