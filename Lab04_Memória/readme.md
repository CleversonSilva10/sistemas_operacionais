Requisitos da atividade:

## 1. Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista); 

Criamos uma struct chamada No, que pode ser chamada como Celula
	
	struct no{
 	  int Registro; // Usamos registro como id da celula
	  int conteudo_1;
	  int conteudo_2;
	  int conteudo_3;
 	  struct no *prox;
	};typedef struct no Celula;
	
	
A opção 3 - (Opção 3. Criar novos objetos na lista) 

A função insere() permite a criação dinâmica de novos objetos na lista, permitindo que o usuário especifique a quantidade desejada de objetos a serem criados.

## 2. Construa uma função que imprima todos os valores da lista; 

A opção 1 (1. Imprimir a lista)

A função imprime() tem como propósito imprimir o conteúdo de cada objeto presente na lista no terminal. Caso a lista esteja vazia, a função imprimirá uma mensagem indicando que a lista não contém nenhum objeto.

	void imprime(Celula *cabeca){
	  Celula *aux = cabeca;
	  int i = 1;
	  if (aux == NULL){
	    printf("\n---------------------------\n");
	    printf("Lista está vazia!"); 
	    printf("\n---------------------------\n");
	  }
	  while(aux != NULL){
	    printf("\nRegistro do No = %d", aux->Registro);
	    printf("\nConteudo 1: %d", aux->conteudo_1);
	    printf("\nConteudo 2: %d", aux->conteudo_2);
	    printf("\nConteudo 3: %d\n", aux->conteudo_3);
	    i++;
	    aux = aux->prox;
	  }
	}

## 3. Calcule a quantidade de memória gasta por cada instância da célula 

A opção 2 (2. Quantidade de memória gasta por cada instância da célula)

Usamos sizeof() para calcular tamanho da instância.

	if (opcao == 2) {
	      printf("\nTamanho da celula = %d Bytes\n", sizeof(Celula));
	    }

## 4. Construa uma função que remove os elementos da lista;

A opção 4 (4. Remover elemento da lista) permite que o usuário selecione o registro que deseja remover, utilizando a função Remover(). 
Essa função tem como objetivo remover o objeto correspondente da lista.

	void Remover(Celula **cabeca, int registro_no){
	  Celula *anterior, *atual;
	  anterior = *cabeca;
	  atual = *cabeca;
	  int Nao_Encontrou_Nada = 0;

	  if (atual == NULL){
	    printf("\n---------------------------\n");
	    printf("Lista está vazia!"); 
	    printf("\n---------------------------\n");
	  }else{
	    anterior = *cabeca;
	    while (atual != NULL){
	      if (registro_no == atual->Registro){
		if (atual == *cabeca){
		  Nao_Encontrou_Nada = 1;
		  *cabeca = atual->prox;
		  printf("\n---------------------------------------\n");
		  printf("Valor encontrado! Removido: %d", registro_no); 
		  printf("\n---------------------------------------\n");
		  Deletar_Celula(&atual);
		  break;
		}else{
		  Nao_Encontrou_Nada = 1;
		  anterior->prox = atual->prox;
		  printf("\n---------------------------------------\n");
		  printf("Valor encontrado! Removido: %d", registro_no); 
		  printf("\n---------------------------------------\n");
		  Deletar_Celula(&atual);
		  break;
		}
	      }else{
		anterior = atual;
		atual = atual->prox;
	      }
	    }
	    if (Nao_Encontrou_Nada == 0){
	      printf("\n----------------------------\n");
	      printf("Celula não existente!");
	      printf("\n----------------------------\n");
	    }
	  }
	}

## 5. Incremente sua função liberando a memória quando um elemento é liberado;
	void Deletar_Celula(Celula **escolhido){
  		free(escolhido);
	}

## 6. Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.

Na opção 5 - Calcular maximo de elementos possiveis

O usuário informar quanto possui de Memória RAM disponível (GB), transformamos GB em Bytes e dividimos total_de_Bytes_Disponivel/Tamanho_da_Celula

	void Max_Elementos(){
	  double qtd_memoria, giga_para_bytes, Qtdade_Max, tamanho_celula;
	  printf("\nInforme qtdade de Memória RAM disponivel (GB): "); scanf("%lf", &qtd_memoria);
	  giga_para_bytes = qtd_memoria*1024*1024*1024; // Transformando em GB PARA BYTES;
	  tamanho_celula = sizeof(Celula);
	  Qtdade_Max = giga_para_bytes/tamanho_celula; 
	  printf("\n---------------------------------------");
	  printf("\nQuantidade de memoria informada: %.2f GB", qtd_memoria);
	  printf("\nTamanho da celula: %.0f Bytes\n", tamanho_celula);
	  printf("GB -> Bytes: %.0f Bytes\n", giga_para_bytes);
	  printf("\nQuantidade máxima = | %.0f Elementos |\n", Qtdade_Max);
	  printf("---------------------------------------\n");
	}
