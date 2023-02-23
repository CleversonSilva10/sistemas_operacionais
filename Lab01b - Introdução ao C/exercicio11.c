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

void somaLinhas(int *l1, int *l2, int coluna){
	
	for(int i = 0; i < coluna; i++){
		l2[i] = l1[i] + l2[i];
	}

}
void multiplicaLinhas(int *l1, int *l2, int coluna){
	
	for(int i = 0; i < coluna; i++){
		l2[i] = l1[i] * l2[i];
	}

}


int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	
	int **matriz, linha, coluna, opcao;
	
	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%d", &linha);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d", &coluna);
	
	matriz = malloc(linha * sizeof(int*));
	for(int i = 0; i < linha; i++){
		matriz[i] = malloc(coluna * sizeof(int));
		for(int j = 0; j < coluna; j++){
			printf("Digite o valor da c�lula [%d,%d]", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Digite 0 para realizar a soma de L1 e L2 e 1 para multiplica��o: ");
	scanf("%d", &opcao);
	if(opcao != 0 && opcao != 1){
		printf("Erro! Somente valores 0 e 1 s�o aceitos!!!");
		return 0;
	}
	if(opcao == 0){
		somaLinhas(matriz[0], matriz[1], coluna);
	}else{
		multiplicaLinhas(matriz[0], matriz[1], coluna);
	}
	printf("Matriz final: \n");
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	free(matriz);
	
	return 0;
}
