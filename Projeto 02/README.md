
~~~
Nome: Cleverson Pereira da Silva TIA: 32198531
Nome: Gustavo Teixeira dos Santos TIA: 32197020
Nome: Pedro Augusto Ferreira Lima TIA: 32136374
~~~

# Sistemas Operacionais - PROJ2 Projeto final

### Como compilar o programa

~~~
gcc -Wall -o projeto2 projeto2.c -lpthread
~~~

### Para executar, utilize este comando:
~~~
./projeto2
~~~

**Nota importante:** O grupo implementou uma função de transferência randômica, a cada execução trará resultados variados. Isso acontece por causa do requisito 4. 

## Função Principal - Main

> * Definimos um vetor de threads e inicializamos as threads utilizando a phtread_create.
> * Passando como parâmetro, vetor de threads, retorno daquele função que será executada (void = NULL), ponteiro da função e a referência da variável **opcao_aleatoria**
> * Utilizamos a variavel "opcao_aleatoria" como uma forma de randomização das transações realizadas pela função.
> * A variável "opcao_aleatoria" pode obter dois valores: 0 e 1.

~~~
   // FEITO POR PEDRO AUGUSTO FERREIRA LIMA

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
~~~


## Comprovando os requisitos - Função transferência

1. A conta to pode receber mais de uma transferência simultânea
2. A conta from pode enviar mais de uma transferência simultânea

**Resposta**: Implementamos uma solução simples para realizar transferências bancárias entre contas, garantindo simultaneamente que as transferências ocorram corretamente entre as contas "from" e "to". Utilizando um Mutex, controlamos o acesso à região crítica do código, permitindo que apenas uma thread execute uma transferência por vez. Dessa forma, evitamos condições de corrida e garantimos a integridade das operações bancárias.

~~~
void *transferencia(void *num){
    int valor = 1;
    int *opcao = (int*) num;

    if (*opcao == 0){
        // FEITO POR GUSTAVO TEIXEIRA DOS SANTOS
        
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
~~~

3. A conta from não pode enviar dinheiro se não tiver mais saldo

**Resposta:** Este requisito foi resolvido de uma forma simples, realizando uma condicional para observar se a conta from possui o valor desejado para transferência.

~~~
if (valor > conta_from) {
            // 3. A conta from não pode enviar dinheiro se não tiver mais saldo;
            printf("\n----------------------------------\n");
            printf("Transferencia cancelada: saldo insuficiente");
            printf("\n----------------------------------\n");
~~~
4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode
receber e a conta que recebia pode enviar.

**Resposta:** Se o valor randômico foi igual 1, irá realizar a transferência desejada no requisito 4. Nesta operação, a conta From irá troca de posição com a conta To. Como estas transferências são randômicas, se executamos o código mais de uma vez não trará o mesmo valor, porém a integridade das transferências estão corretas. 

~~~
if (*opcao == 1){
        // FEITO POR CLEVERSON PEREIRA DA SILVA
        
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
~~~

5. Poderão ser realizadas até 100 transações simultâneas de transferência.

**Resposta:** Definimos uma variável global com número máximo de threads

~~~
#define NUM_TRANSACOES 100
~~~

# Conclusão

**Conclusão Final:** Este projeto mostrou para grupo a importância das threads e como gerenciar de forma inteligente. Utilizando o Mutex podemos manter a integridade dos valores da variáveis de forma simultânea e com isso evitando a condição de corrida.

#Execução do Código.
~~~
CONTA FROM INCIAL: 1000
CONTA TO INCIAL: 100

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 99
Conta To: 1001
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 98
Conta To: 1002
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 97
Conta To: 1003
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 96
Conta To: 1004
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1003
Conta To: 97
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 96
Conta To: 1004
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1003
Conta To: 97
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1002
Conta To: 98
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1001
Conta To: 99
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 98
Conta To: 1002
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 97
Conta To: 1003
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 96
Conta To: 1004
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 95
Conta To: 1005
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 94
Conta To: 1006
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 93
Conta To: 1007
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 92
Conta To: 1008
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1007
Conta To: 93
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1006
Conta To: 94
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1005
Conta To: 95
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1004
Conta To: 96
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1003
Conta To: 97
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1002
Conta To: 98
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1001
Conta To: 99
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 1000
Conta To: 100
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 999
Conta To: 101
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 998
Conta To: 102
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 101
Conta To: 999
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 998
Conta To: 102
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 997
Conta To: 103
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 996
Conta To: 104
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 995
Conta To: 105
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 994
Conta To: 106
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 105
Conta To: 995
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 104
Conta To: 996
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 995
Conta To: 105
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 994
Conta To: 106
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 993
Conta To: 107
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 992
Conta To: 108
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 107
Conta To: 993
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 992
Conta To: 108
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 991
Conta To: 109
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 990
Conta To: 110
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 989
Conta To: 111
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 988
Conta To: 112
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 987
Conta To: 113
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 986
Conta To: 114
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 985
Conta To: 115
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 984
Conta To: 116
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 983
Conta To: 117
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 982
Conta To: 118
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 117
Conta To: 983
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 982
Conta To: 118
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 981
Conta To: 119
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 980
Conta To: 120
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 979
Conta To: 121
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 978
Conta To: 122
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 977
Conta To: 123
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 976
Conta To: 124
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 975
Conta To: 125
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 974
Conta To: 126
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 973
Conta To: 127
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 972
Conta To: 128
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 127
Conta To: 973
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 972
Conta To: 128
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 971
Conta To: 129
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 970
Conta To: 130
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 969
Conta To: 131
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 968
Conta To: 132
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 967
Conta To: 133
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 966
Conta To: 134
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 965
Conta To: 135
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 964
Conta To: 136
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 963
Conta To: 137
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 962
Conta To: 138
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 961
Conta To: 139
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 960
Conta To: 140
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 959
Conta To: 141
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 958
Conta To: 142
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 957
Conta To: 143
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 956
Conta To: 144
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 955
Conta To: 145
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 954
Conta To: 146
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 953
Conta To: 147
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 146
Conta To: 954
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 145
Conta To: 955
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 954
Conta To: 146
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 145
Conta To: 955
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 954
Conta To: 146
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 953
Conta To: 147
----------------------------------

----------------------------------
CONTA FROM -> CONTA TO | CONTA TO -> CONTA FROM

Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 146
Conta To: 954
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 953
Conta To: 147
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 952
Conta To: 148
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 951
Conta To: 149
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 950
Conta To: 150
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 949
Conta To: 151
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 948
Conta To: 152
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 947
Conta To: 153
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 946
Conta To: 154
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 945
Conta To: 155
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 944
Conta To: 156
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 943
Conta To: 157
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 942
Conta To: 158
----------------------------------

----------------------------------
Transferencia realizada com sucesso
Conta From enviou: -1 || Conta To recebeu: +1
Conta From: 941
Conta To: 159
----------------------------------


---------------------------------------------
Transferências concluídas e memória liberada.
---------------------------------------------
~~~

