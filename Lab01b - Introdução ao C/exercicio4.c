#include <stdio.h>
#include <locale.h>

void integrantes_grupo(){
  printf("\n----------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374\n");
  printf("----------------------------------------------\n\n");
};

int tamanho(char *x){ // Fun��o que retorna o tamanho de uma palavra/frase
	int i = 0;
	while(x[i] != '\0'){
		i++;
	}
	return i;
}

int numero(char x){ // Fun��o que retorna o valor inteiro de um n�mero sem considerar se � maiusculo ou minusculo
	
	if((int) x >= 65 && (int) x <= 91){
		return (int) x + 32;
	}else{
		return (int) x;
	}
	
}

int ordemAlfabetica(char *a, char *b){ // -1 se A � maior; 1 se B � maior e 0 se s�o iguais
	
	int i = 0;
	while(a[i] != '\0' && b[i] != '\0'){
		
		if(numero(a[i]) < numero(b[i])){
			return -1;
		}else if (numero(a[i]) > numero(b[i])){
			return 1;
		}
		i++;
	}
	
	if(tamanho(a) < tamanho(b)){
		return -1;
	}else if(tamanho(a) > tamanho(b)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	
	char a[50], b[50];
	int result;
	
	printf("Por favor, digite o primeiro nome: ");
	scanf("%50[^\n]", a);
	getchar();
	printf("Por favor, digite o segundo nome: ");
	scanf("%50[^\n]", b);
	result = ordemAlfabetica(a,b);
	if(result == -1){
		printf("%s, %s", a,b);
	}else if(result == 1){
		printf("%s, %s", b, a);
	}else{
		printf("Os dois nomes s�o iguais!");
	}
	
	return 0;
}
