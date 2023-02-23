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

int **retornaPositivo(int **matriz, int linha, int coluna){ // Fun��o para retornar a matriz somente com correspondentes inteiros
	
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			if(matriz[i][j] < 0){
				matriz[i][j] = matriz[i][j] * -1;
			}
		}
	}
	
	return matriz;
	
}

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	int **matriz, linha, coluna;
	
	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%d", &linha);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d", &coluna);
	
	matriz = malloc(linha * sizeof(int*));
	for(int i = 0; i < linha; i++){
		matriz[i] = malloc(coluna * sizeof(int));
		for(int j = 0; j < coluna; j++){
			printf("Digite o valor da c�lula [%d,%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	matriz = retornaPositivo(matriz, linha, coluna);
	
	printf("Matriz final: \n");
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
