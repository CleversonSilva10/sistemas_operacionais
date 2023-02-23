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

int **multiplicaMatriz(int **matriz, int linha, int coluna, int linhaOuColuna, int valor, int escolhida){
	
	if(linhaOuColuna == 0){ // Multiplicar a linha
		
		for(int i = 0; i < coluna; i++){
			matriz[escolhida][i] = matriz[escolhida][i] * valor;
		}
		
	}else{ // Multiplicar a coluna
	
		for(int i = 0; i < linha; i++){
			matriz[i][escolhida] = matriz[i][escolhida] * valor;
		}
		
	}
	
	return matriz;
	
}

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	int **matriz, linha, coluna, escolhida, linhaOuColuna, valor; // linhaOuColuna = 0 se for linha e 1 se for coluna
	
	printf("Digite a quantidade de linhas: ");
	scanf("%d", &linha);
	printf("Digite a quantidade de colunas: ");
	scanf("%d", &coluna);
	
	matriz = malloc(linha * sizeof(int*));
	for( int i = 0; i < linha; i++){
		matriz[i] = malloc(coluna * sizeof(int));
		for( int j = 0; j < coluna; j++){
			printf("Digite o valor de [%d,%d]", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	while(1){
		
		printf("Digite 0 para multiplicar linha e 1 para multiplicar coluna: ");
		scanf("%d", &linhaOuColuna);
		if(linhaOuColuna != 1 && linhaOuColuna != 0){
			printf("Por favor, digite 0 para linha e 1 para coluna!!!\n\n");
			continue;
		}
		printf("Digite o n�mero da linha / coluna que deseja multiplicar (de 0 a n): ");
		scanf("%d", &escolhida);
		if(escolhida < 0 || (linhaOuColuna == 0 && escolhida >= linha) || (linhaOuColuna == 1 && escolhida >= coluna)){
			printf("Por favor, digite o n�mero da linha / coluna v�lido!!!\n\n");
			continue;
		}
		printf("Escolha o valor que multiplicar� a linha / coluna: ");
		scanf("%d", &valor);
		
		break;
	}
	
	matriz = multiplicaMatriz(matriz, linha, coluna, linhaOuColuna, valor, escolhida);
	
	printf("Nova matriz: \n");
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
