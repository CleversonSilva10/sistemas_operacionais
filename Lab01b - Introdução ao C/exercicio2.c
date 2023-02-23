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
	float nota[3], me, ma;
	
	for(int i = 0 ; i < 3; i++){
		printf("Digite a nota %d: ", i + 1);
		scanf("%f", &nota[i]);
	}
	
	printf("Digite a M�dia das notas dos exerc�cios: ");
	scanf("%f", &me);
	
	ma = (nota[0] + nota[1]*2 + nota[2]*3 + me)/7;
	
	if(ma >= 9){
		printf("A");
	}else if(ma >= 7.5){
		printf("B");
	}else if(ma >= 6){
		printf("C");
	}else if(ma >= 4){
		printf("D");
	}else{
		printf("E");
	}
	
	return 0;
}
