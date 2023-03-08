#include <stdio.h>
#include <string.h>

void integrantes() {
  printf("\nIntegrantes\n--------------------------------------------------\n");
  printf("Nome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020\n");
  printf("Nome: Pedro Augusto Ferreira Lima - TIA: 32136374");
  printf("\n--------------------------------------------------\n");
}

void leitura_txt() {
  char linha[100];
  FILE *arquivo, *arquivo_copia;
  char nome_arquivo[100];
  char arquivo_clonado[100];
  printf("\nDigite nome do arquivo desejado: ");
  scanf("%s", nome_arquivo);
  arquivo = fopen(nome_arquivo, "r");

  if (arquivo != NULL) {
    printf("\nQual nome você deseja para arquivo de saída?: ");
    scanf("%s", arquivo_clonado);
    arquivo_copia = fopen(arquivo_clonado, "w");
    printf("\ncp %s %s\n", nome_arquivo, arquivo_clonado);
    while (fgets(linha, 100, arquivo)) {
      fprintf(arquivo_copia, "%s", linha);
    }
    printf("\n------------------------------------");
    printf("\nO arquivo foi clonado com sucesso!!\n");
    printf("------------------------------------\n\n");
    fclose(arquivo);
    fclose(arquivo_copia);
  } else {
    printf("\n------------------------------------");
    printf("\nO arquivo não foi encontrado!!\n");
    printf("------------------------------------");
  }
}

int main() {
  integrantes();
  leitura_txt();
  return 0;
}