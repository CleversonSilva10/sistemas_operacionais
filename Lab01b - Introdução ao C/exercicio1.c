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

int devolveLinhaMenor(int **matriz, int n){
	int linhaMenor, numeroMenor;
	
	linhaMenor = 0;
	numeroMenor = matriz[0][0];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matriz[i][j] < numeroMenor){
				linhaMenor = i;
				numeroMenor = matriz[i][j];
			}
		}
	}
	return linhaMenor;
}

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	int **matriz, n;
	
	printf("Por favor, digite o n�mero de linhas / colunas da matriz quadrada: ");
	scanf("%d", &n);
	
	matriz = malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++){
		matriz[i] = malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			printf("Por favor, digite o valor de [%d, %d]", i,j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("A linha com o menor n�mero �: %d", devolveLinhaMenor(matriz, n));
	
	return 0;
}
