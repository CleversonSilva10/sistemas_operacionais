#include <iostream>
#include <locale.h>

using namespace std;

void integrantes_grupo(){
  printf("\n----------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531");
  printf("\nNome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374\n");
  printf("----------------------------------------------\n\n");
};

int tamanho(string x){ // Fun��o que retorna o tamanho de uma palavra/frase
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

int ordemAlfabetica(string a, string b){ // -1 se A � maior; 1 se B � maior e 0 se s�o iguais
	
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
	string a, b;
	int result;
	
	setlocale(LC_ALL, "Portuguese");
	
	cout <<"Por favor, digite o primeiro nome: ";
	getline(cin, a);
	cout <<"Por favor, digite o segundo nome: ";
	getline(cin, b);
	result = ordemAlfabetica(a,b);
	if(result == -1){
		cout << a << ", " << b;
	}else if(result == 1){
		cout << b << ", " << a;
	}else{
		cout << "Os dois nomes s�o iguais!";
	}
	
	return 0;
}
