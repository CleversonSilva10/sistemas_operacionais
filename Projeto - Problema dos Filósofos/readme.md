Problema dos Filósofos

Gustavo Teixeira dos Santos  TIA: 32197020

Cleverson Pereira da Silva  TIA: 32198531

Pedro Augusto Lima  TIA: 32136374

Em nosso programa, utilizamos Threads ao invés de processos. Mesmo assim, ainda temos que resolver o problema de comunicação entre elas, uma vez que elas utilizam variáveis compartilhadas. Para resolver isso, utilizamos o conceito de semáforo. Com isso, criamos um semáforo que controla qual Thread pode mudar de estado e tentar "pegar os garfos". Dessa forma, garantimos que apenas um "filósofo" por vez muda de estado e interage com as variáveis compartilhadas.

Outra tarefa também foi o uso do conceito de Preempsão para evitar Deadlocks. O que faz com que um filósofo só pegue os garfos quando os dois estiverem disponíveis. Impedindo que ele fique com um garfo na mão enquanto espera o outro e trava o processo. Pois, se todos os filósofos ficarem com um garfo na mão e esperando o segundo, teremos um Deadlock.