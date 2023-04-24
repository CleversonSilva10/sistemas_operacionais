Requisitos da atividade:

1. Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista); 
Reposta: Criamos uma struct chamada No, que pode ser chamada como Celula
	struct no{
 	  int Registro; // Usamos registro como id da celula
	  int conteudo_1;
	  int conteudo_2;
	  int conteudo_3;
 	  struct no *prox;
	};typedef struct no Celula;
A opção (Opção 3. Criar novos objetos na lista) - A função insere() está de uma forma dinâmica para criação de novos objetos na lista. É necessário o usuário informar quantos objetos necessita!

2. Construa uma função que imprima todos os valores da lista; 

Reposta: A opção 1 (1. Imprimir a lista), possui uma função chamada imprime (), ela tem como objetivo printar o conteúdo de cada objeto na lista no terminal e caso não tenha nenhum objeto, ela printa que lista está vazia!

3. Calcule a quantidade de memória gasta por cada instância da célula 

Resposta: A opção 2 (2. Quantidade de memória gasta por cada instância da célula), usamos sizeof() para calcular tamanho da instância

4. Construa uma função que remove os elementos da lista;

Resposta: A opção 4 (4. Remover elemento da lista), solicita para usuário qual registro ele quer remover e a função Remover() tem como objetivo remover o objeto da lista

5. Incremente sua função liberando a memória quando um elemento é liberado;
	void Deletar_Celula(Celula **escolhido){
  		free(escolhido);
	}

6. Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.

Reposta: O usuário informar quanto possui de Memória RAM disponível (GB), transformamos GB em Bytes e dividimos total_de_Bytes_Disponivel/Tamanho_da_Celula
