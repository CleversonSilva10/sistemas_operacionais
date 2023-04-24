#include <stdio.h>
#include <stdlib.h>

void id_alunos() {
  printf("\n--------------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374");
  printf("\n--------------------------------------------------\n");
}

void menu() {
  printf("\n----------- MENU ---------------");
  printf("\n1. Imprimir a lista\n");
  printf("2. Quantidade de memória gasta por cada instância da célula\n");
  printf("3. Criar novos objetos na lista\n");
  printf("4. Remover elemento da lista\n");
  printf("5. Calcular maximo de elementos possiveis");
  printf("\n6. Encerrar o programa!\n");
  printf("--------------------------------\n");
}

struct no{
  int Registro;
  int conteudo_1;
  int conteudo_2;
  int conteudo_3;
  struct no *prox;
};typedef struct no Celula;

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

void insere(Celula **cabeca, int registro_no, int valor1, int valor2, int valor3){
  Celula *novo_no = malloc(sizeof(Celula));
  novo_no->Registro = registro_no;
  novo_no->conteudo_1 = valor1;
  novo_no->conteudo_2 = valor2;
  novo_no->conteudo_3 = valor3;
  novo_no->prox = NULL;
  if (*cabeca == NULL){
      *cabeca = novo_no;
  }else{
    Celula *aux = *cabeca;
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

void Deletar_Celula(Celula **escolhido){
  free(escolhido);
}

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

int main(void) {
  int opcao, qtd, i;
  id_alunos();
  Celula *cabeca = NULL;

  while (1){
    menu();
    printf("\nDigite a opção desejada: ");
    
    scanf("%d", &opcao);
    if (opcao == 1) {
      imprime(cabeca);
    }
    if (opcao == 2) {
      printf("\nTamanho da celula = %d Bytes\n", sizeof(Celula));
    }
    if (opcao == 3){
      printf("\nDigite quantos objetos deseja inserir: "); scanf("%d", &qtd);
      for (i = 0; i<qtd; i++){
        int valor1, valor2, valor3, registro_no;
        printf("\nInserindo %d elemento", i+1);
        printf("\nRegistro do Nó: "); scanf("%d", &registro_no);
        printf("Digite valor 1: "); scanf("%d", &valor1);
        printf("Digite valor 2: "); scanf("%d", &valor2);
        printf("Digite valor 3: "); scanf("%d", &valor3);
        insere(&cabeca, registro_no, valor1, valor2, valor3);
        printf("\n");
      }
    }
    if (opcao == 4){
      int no_desejado;
      printf("\nInforme o valor do Registro do No (Remoção): "); scanf("%d", &no_desejado);
      Remover(&cabeca, no_desejado);
    }
    if (opcao == 5){
      Max_Elementos();
    }
    if (opcao == 6){
      printf("\n---------------------------------------\n");
      printf("Programa encerrado!"); 
      printf("\n---------------------------------------\n");
      break;
    }
  }
  return 0;
}
