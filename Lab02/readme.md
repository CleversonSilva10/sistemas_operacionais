Respostas Execícios:

1) Não. Como com o fork() o algoritmo cria "processos filhos" que, por sua vez compartilhar a mesma CPU e endereços de memória. Porém, rodam de formas "independentes" um do outro. Com isso, não há uma sequência que garanta que os valores de i sejam exibidos de forma ordenada.

2) Em sua prática nada. O sys.stderr (ou System Standard Error) é, por boa prática e praticidade, utilizado geralmente para exibir mensagens de erros. Porém, pode ser usado para imprimir resultador para os usuários. Usando o printf() o output ficaria assim: printf("i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
