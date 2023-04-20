#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void id_alunos(){
  printf("\n--------------------------------------------------");
  printf("\nNome: Cleverson Pereira da Silva - TIA: 32198531\n");
  printf("Nome: Gustavo Teixeira dos Santos - TIA: 32197020");
  printf("\nNome: Pedro Augusto Ferreira Lima - TIA: 32136374");
  printf("\n--------------------------------------------------\n");
}

double soma = 0.0;
long long n = 1000000000;
int num_threads = 3;
pthread_mutex_t mutex;
long long limite_iteracoes = 1000000; // Quanto mais aumentar limite de iterações, mais proximo chegará aproximadamente de pi

void *SOMA_THREAD_COM_MUTEX(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/num_threads;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    long long iteracoes = 0;

    if (my_first_i % 2 == 0) {
        factor = 1.0;
    } else {
        factor = -1.0;
    }

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
      double minha_soma = factor/(2*i+1);
      pthread_mutex_lock(&mutex);
      soma += minha_soma;
      pthread_mutex_unlock(&mutex);
      iteracoes++;
      if (iteracoes >= limite_iteracoes) {
          pthread_exit(NULL);
        }
   }
  return NULL;
}

void* Soma_Thread_SEM_MUTEX(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / num_threads;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    
    if (my_first_i % 2 == 0) {
        factor = 1.0;
    } else {
        factor = -1.0;
    }
    
    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        soma += factor / (2*i+1);
    }
    return NULL;
}

int main(){
  id_alunos();
  long thread;
  pthread_t* id_threads;
  
  pthread_mutex_init(&mutex, NULL);
  id_threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));
  
  for (thread = 0; thread < num_threads; thread++){
    pthread_create(&id_threads[thread], NULL, SOMA_THREAD_COM_MUTEX, (void*) thread);
  }
  
  for (thread = 0; thread < num_threads; thread++) {
    pthread_join(id_threads[thread], NULL);
  }

  double pi = 4.0*soma;
  printf("\nQuantidade de Threads: %d\nValor de PI aproximadamente (Threads - COM MUTEX) = %.15f\n", num_threads, pi);
  pthread_mutex_destroy(&mutex);

  
  for (thread = 0; thread < num_threads; thread++) {
    pthread_create(&id_threads[thread], NULL, Soma_Thread_SEM_MUTEX, (void*) thread);
  }
    
  for (thread = 0; thread < num_threads; thread++) {
    pthread_join(id_threads[thread], NULL);
  }
    
  soma = 4.0 * soma;
  printf("Valor de PI aproximadamente (Threads - SEM MUTEX) = %.15f\n", soma);
    
  free(id_threads);
  
  return 0;
}
