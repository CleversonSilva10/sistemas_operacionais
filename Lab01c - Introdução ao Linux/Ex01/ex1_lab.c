#include <stdio.h>

void integrantes() {
  printf("\nIntegrantes\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
  printf("Nome: Pedro Augusto Ferreira Lima - TIA: 32136374");
  printf("\n--------------------------------------------------\n");
}

void leitura_txt() {
  FILE *arquivo;
  char linha[100];
  char nome_arquivo[100];
  printf("\ncat: ");
  scanf("%s", nome_arquivo);
  arquivo = fopen(nome_arquivo, "r");

  if (arquivo != NULL) {
    printf("\n------------------------------------");
    printf("\nO arquivo foi encontrado com sucesso!!\n");
    printf("------------------------------------\n\n");
    printf("\ncat %s\n\n", nome_arquivo);
    while (fgets(linha, 100, arquivo)) {
      printf("%s", linha);
    }
    fclose(arquivo);
  } else {
    printf("\n------------------------------------");
    printf("\nO arquivo não foi encontrado!!\n");
    printf("------------------------------------");
  }
}

int main(void){
  integrantes();
  leitura_txt();
  return 0;
}