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

