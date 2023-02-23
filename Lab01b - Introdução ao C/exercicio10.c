#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

