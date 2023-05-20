#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

// 64kB stack

#define FIBER_STACK 1024*64
#define NUM_TRANSACOES 100

int conta_to = 100;
int conta_from = 1000;
pthread_mutex_t mutex;

// struct c {
//  int saldo;
// };

// typedef struct c conta;
// conta from, to;

// int valor;

// The child thread will execute this function

void *transferencia(void *num){
    srand(time(NULL));
    int valor = 1;
    int *opcao = (int*) num;

    if (*opcao == 0){
        // Região Critica
        pthread_mutex_lock(&mutex);
        //printf("\nTHREAD INICADA %d", *numero);
        
        // 1. A conta to pode receber mais de uma transferência simultânea;
        // 2. A conta from pode enviar mais de uma transferência simultânea;
        if (valor > conta_from) {
            // 3. A conta from não pode enviar dinheiro se não tiver mais saldo;
            printf("\n----------------------------------\n");
            printf("Transferencia cancelada: saldo insuficiente");
            printf("\n----------------------------------\n");
        }else{
            conta_to += valor;
            conta_from -= valor;
            printf("\n----------------------------------\n");
            printf("Transferencia realizada com sucesso\n");
            printf("Conta From enviou: -%d || Conta To recebeu: +%d", valor, valor);
            printf("\nConta From: %d\nConta To: %d\n", conta_from, conta_to);
            printf("----------------------------------\n");
        }
        pthread_mutex_unlock(&mutex);
    }

    if (*opcao == 1){
        
        pthread_mutex_lock(&mutex);
        //printf("\nTHREAD INICADA %d", *numero);
        // Região Critica
        
        // 4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar;
        // CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM
        
        if (valor > conta_to) {
            printf("\n----------------------------------\n");
            printf("Transferencia cancelada: saldo insuficiente");
            printf("\n----------------------------------\n");
        }else{
            conta_to -= valor;
            conta_from += valor;
            printf("\n----------------------------------\n");
            printf("CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM\n\n");
            printf("Transferencia realizada com sucesso\n");
            printf("Conta From enviou: -%d || Conta To recebeu: +%d", valor, valor);
            printf("\nConta From: %d\nConta To: %d\n", conta_to, conta_from);
            printf("----------------------------------\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(int argc, char *argv[]){
    void* stack;
    //pid_t pid;
    //5. Poderão ser realizadas até 100 transações simultâneas de transferência
    pthread_t threads[NUM_TRANSACOES];
    int i;
    
    // Allocate the stack
    stack = malloc(FIBER_STACK);
        if ( stack == 0 )
        {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    i = 0;
    while(i < NUM_TRANSACOES){
        int opcao_aleatoria = rand()%2; // MOD 
        pthread_create(&threads[i], NULL, *transferencia, &opcao_aleatoria);
        i++;
    }

    i = 0;
    while(i < NUM_TRANSACOES){
        pthread_join(threads[i], NULL);
        i++;
    }

    
    // Free the stack
    free(stack);
    printf("\n\n---------------------------------------------");
    printf("\nTransferências concluídas e memória liberada.\n");
    printf("---------------------------------------------\n\n");
    return 0;
}

