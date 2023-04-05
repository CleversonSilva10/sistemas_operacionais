// Gustavo Teixeira dos Santos  TIA: 32197020
// Cleverson Pereira da Silva TIA: 32198531

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>

int n, m; // Tamanho das colunas e linhas
int thread_count; // Contador de threads
float *y, **a, *x;

// Mudamos essa função para ficar mais adequada com o nosso código. Agora, ele cria uma thread para cada linha da matriz, fazendo com que tenha uma thread para cada linha da matriz
// Não temos problema de deadlock ou condição de corrida pois cada thread vai mexer em uma linha da matriz e, mesmo que leiam os mesmos valores do vetor x, não está modificando. Por isso não temos problemas nas threads.
void *pth_math_vect(void *rank){
	
	long my_rank = (long) rank;
	int j;
	
	y[my_rank] = 0.0;
	for(j = 0; j < n; j++){
		y[my_rank] += a[my_rank][j] * x[j];
	}
	return NULL;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int option;
	printf("Você quer:\n\t1 - Escrever seus próprios valores\n\t2 - Resolver um exercício pronto\nEscolha: ");
	scanf("%d", &option);
	if(option == 1){
		int value;
		printf("por favor, digite o valor de n:");
		scanf("%d", &n);
		printf("Por favor, digite o valor de m:");
		scanf("%d",&m);
		
		// Criando o vetor
		x = (float*)malloc(n * sizeof(float));
	
		// Criando as matrizes
		a = (float**)malloc(m * sizeof(float*));
		for(int i = 0; i < m; i++){
			a[i] = (float*) malloc(n * sizeof(float));
		}
	
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				printf("Digite o valor da linha %d e coluna %d da matriz: ", i, j);
				scanf("%f", &a[i][j]);
			}
		}
		
		for(int i = 0; i < n; i++){
			printf("Digite o valor da linha %d do vetor: ", i);
			scanf("%f", &x[i]);
		}
		
	}else{
		n = 3;
		m = 3;
		
		a = (float**) malloc(3 * sizeof(float*));		
		for(int i = 0; i < 3; i++){
			a[i] = (float*)malloc(3 * sizeof(float));
			for(int j = 0; j < 3; j++){
				a[i][j] = (float)3*i+(j+1);
			}
		}
		x = (float*)malloc(3 * sizeof(float));
		x[0] = 2.0;
		x[1] = 3.0;
		x[2] = 4.0;
		
	}
	
	y = (float*) malloc(n * sizeof(float));
	
	thread_count = m;
	pthread_t thread[m];
	
	for(int i = 0; i < m; i++){
		pthread_create(&thread[i], NULL, pth_math_vect, i);
	}
	for(int i = 0; i < m; i++){
		pthread_join(&thread[i], NULL);
	}
	
	for(int j = 0; j < n; j++){
			printf("%f ", y[j]);
		}
	
	free(y);
	return 0;
}
