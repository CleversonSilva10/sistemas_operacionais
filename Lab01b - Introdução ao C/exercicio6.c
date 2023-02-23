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

int **transposta(int **matriz, int *linha, int *coluna){
	
	int temp;
	
	int **novaMatriz = malloc(*coluna * sizeof(int*));
	printf("Foi\n");
	for (int i = 0; i < *coluna; i++){
		novaMatriz[i] = malloc(*linha * sizeof(int));
		for(int j = 0; j < *linha; j++){
			novaMatriz[i][j] = matriz[j][i];
		}
	}
	
	temp = *coluna;
	*coluna = *linha;
	*linha = temp;
	printf("linha : %d; coluna: %d\n", *linha, *coluna);
	return novaMatriz;
	
}

int main(){
	int **matriz, linha, coluna;
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	
	printf("Por favor, digite a quantidade de linhas da matriz: ");
	scanf("%d",&linha);
	printf("Por favor, digite a quantidade de colunas da matriz: ");
	scanf("%d",&coluna);
	
	matriz =  malloc(linha * sizeof(int*));
	for(int i = 0; i < linha; i++){
		matriz[i] = malloc(coluna * sizeof(int));
		for(int j = 0; j < coluna; j++){
			printf("Digite o valor na posi��o [%d,%d]: ",i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Matriz original: \n");
	for(int i = 0; i < linha; i++){
		for (int j = 0; j < coluna; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	matriz = transposta(matriz, &linha, &coluna);
	printf("Matriz transposta: \n");
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
}
