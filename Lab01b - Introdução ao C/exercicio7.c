#include <stdio.h>
#include <locale.h>

void integrantes_grupo(){
  printf("\n----------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374\n");
  printf("----------------------------------------------\n\n");
};

typedef struct{
	
	char nome[50];
	int idade;
	float peso;
	float altura;
	
}pessoa;

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	pessoa Pessoa[3];
	
	for(int i = 0; i < 3; i++){
		printf("Digite o nome da %d pessoa: ", i+1);
		scanf("%50[^\n]", Pessoa[i].nome);
		printf("Digite a idade da %d pessoa: ", i+1);
		scanf("%d", &Pessoa[i].idade);
		printf("Digite o peso em kg da %d pessoa: ", i+1);
		scanf("%f", &Pessoa[i].peso);
		printf("Digite a altura em metros da %d pessoa: ", i+1);
		scanf("%f", &Pessoa[i].altura);
		getchar();
	}
	
	for(int i = 0; i < 3; i++){
		printf("Dados da %d pessoa: \n",i + 1);
		printf("Nome: %s, Idade: %d, Peso: %f kg, Altura: %f metros\n", Pessoa[i].nome, Pessoa[i].idade, Pessoa[i].peso, Pessoa[i].altura);
	}
	
	return 0;
}
