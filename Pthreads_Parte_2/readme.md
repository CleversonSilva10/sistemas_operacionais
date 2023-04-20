a) No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?

Resposta: A divergência de resultados causada por uma função sem mutex é devida à condição de corrida, na qual várias threads tentam acessar 
a mesma variável compartilhada simultaneamente, resultando em valores inseguros e inconsistentes. Essa variação 
nos valores é observada a cada utilização do código.

b) Implemente uma solução utilizando Mutex e compare com a anterior. O que mudou? Por quê?

Resposta: Ao utilizar uma função com mutex, a garantia da exclusão mútua assegura que as threads acessam a variável compartilhada de forma sequencial e segura, 
o que resulta na obtenção de resultados precisos e evita inconsistências nos valores. Portanto, utilizando mutex podemos obter valores sempre consistentes e seguros
