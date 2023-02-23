#include <stdio.h>
#include <locale.h>

void integrantes_grupo(){
  printf("\n----------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374\n");
  printf("----------------------------------------------\n\n");
};

int tamanho(char *str){ // Fun��o para retornar o tamanho da string
	
	int contador = 0;
	while(str[contador] != '\0'){
		contador++;
	}
	
	return contador;
	
}

void retornaRecorrencia(char *str, char caractere, int *aparicao, int *quantidadeAparicao){ // Fun��o para encontrar uma recorr�ncia
	
	int contador = 0;
	while(str[contador] != '\0'){
		if(str[contador] == caractere){
			aparicao[*quantidadeAparicao] = contador;
			(*quantidadeAparicao)++;
		}
		contador++;
	}
	
}

void removeCaractere(char *str, char caractere){ // Fun��o para remover um caractere da string
	
	int contador = 0, contadorSecundario = 0;
	while(str[contador] != '\0'){
		if(str[contador] == caractere){
			contadorSecundario = contador;
			while(str[contadorSecundario] != '\0'){
				str[contadorSecundario] = str[contadorSecundario + 1];
				contadorSecundario++;
			}
		}
		contador++;
	}
	
}

void insereCaractere(char *str, char caractere, int posicao){ // Func��o para adicionar um caractere em uma determinada posi��o
	
	int contador = tamanho(str) ;
	while(contador > posicao){
		str[contador] = str[contador - 1];
		contador--;
	}
	str[posicao] = caractere;
	
}

int main(){
	integrantes_grupo();
	setlocale(LC_ALL, "Portuguese");
	
	char str[100], caractere;
	int quantidadeAparicao = 0, aparicao[100], opcao, posicao; // Tem 100 posi��es porque teoricamente � poss�vel inserir uma string com 100 caracteres iguais
	
	printf("Digite uma string de at� 100 caracteres: ");
	gets(str);
	printf("Digite o caractere desejado: ");
	caractere = getchar();
	printf("Digite a op��o:\n\t1 - encontrar um certo caractere na string;\n\t2 - Remover um caractere da string;\n\t3 - Adicionar um caractere na string.\nEscolha: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		
		case 1: // Encontrar um caractere
			retornaRecorrencia(str, caractere, aparicao, &quantidadeAparicao);
			printf("H� %d recorr�ncia(s) desse caractere na string nas posi��es: \n", quantidadeAparicao);
			for(int i = 0; i < quantidadeAparicao; i++){
				printf("%d ", aparicao[i]);
			}
		break;
		case 2: // Remover um caractere da string
			removeCaractere(str, caractere);
			printf("String sem os caracteres: %s", str);
		break;
		case 3: // Adicionar um caractere na string
			if(tamanho(str) < 100){
				printf("Digite a posi��o desejada na string: ");
				scanf("%d", &posicao);
				if(posicao >= 0 && posicao < 100){
					insereCaractere(str, caractere, posicao);
					printf("Nova string: %s", str);
				}else{
					printf("Posi��o inv�lida!");
				}
					
			}else{
				printf("A string ja est� com o seu tamanho m�ximo!");
			}
		break;
		default:
			printf("Erro! voc� selecionou uma op��o incorreta!");
		break;
	}
	
	return 0;
}
