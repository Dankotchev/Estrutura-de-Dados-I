# Lista de Exercícios
## Pilhas Dinâmicas
### Exercício 01:

Uma pilha representa uma estrutura de dados em que os elementos só podem ser inseridos (empilhados) e removidos (desempilhados) do topo (início da lista). Codifique, compile e execute um programa que implemente as operações empilhar e desempilhar do TAD pilha usando os conceitos de lista linear simplesmente encadeada formada por
números reais:

a. Inserir um elemento no início da lista;
b. Remover um elemento do início da lista;
c. Exibir elementos da lista.

### Exercício 02:

Usando a Linguagem C:

a. Como você definiria o tipo pilha usando a representação de lista simplesmente encadeada? Considere, para isto, uma pilha de pratos contendo os campos: cor (branco, preto, roxo, etc) e formato (redondo, quadrado, retangular, etc).
b. Desenvolva a função Pilha* pilha_inicializa (Pilha* p)
c. Desenvolva a função Pilha* pilha_insereTopo (Pilha* p, Prato x)
d. Na função main crie uma variável do tipo da estrutura Pilha. Em seguida chame a função pilha_inicializa e pilha_insereTopo.


### Exercício 03:

Crie uma nova aplicação utilizando a mesma estrutura da questão 2), letra a). Em seguida, usando a linguagem C:

a. Desenvolva a função void pilha_inicializa(Pilha** p)
b. Desenvolva a função void pilha_insereTopo(Pilha** p, Prato x)
c. Na função main crie uma variável do tipo da estrutura Pilha*. Em seguida chame a função pilha_inicializa e pilha_insereTopo.

### Exercício 04:

Compare as implementações da função main() nas questões 2 questões anteriores, apresentando passo a passo o que é criado em memória.


### Exercício 05:

Dada uma pilha P, codifique uma função que inverta a ordem dos elementos dessa pilha utilizando apenas uma estrutura auxiliar. Obs: - Defina adequadamente a estrutura auxiliar; - atente sobre a possibilidade da pilha estar vazia.

### Exercício 06:

Codifique uma função que troque de lugar o elemento que está no topo de uma pilha de caracteres com o que está na base da pilha. Usar apenas uma pilha como auxiliar e, caso necessário, ponteiros do tipo char.

### Exercício 07:

Dada uma pilha dinâmica S, com seu estado atual representado na figura abaixo, e a variável i do tipo primitivo char, desenhe o estado da pilha quando as seguintes operações são executadas:

 
'L'
'V'
'O'

a. i = pop (&S);
b. pop (&S);
c. push (&S, ‘I’);
d. push (&S, ‘A’)

### Exercício 08:

Qual o valor do topo após cada operação do exercício anterior?

a. S->topo =
b. S->topo =
c. S->topo =
d. S->topo =

## Fila Dinâmica
### Exercício 09:

Uma fila representa uma estrutura de dados em que o processo de inserção só acontece
no final da fila e a remoção somente no início. Codifique, compile e execute um
programa que permita fazer as operações de inserção e remoção sobre o TAD fila
usando os conceitos de lista linear simplesmente encadeada formada por números
inteiros:

a. Inserir um elemento no final da lista;
b. Remover um elemento do início da lista;
c. Exibir elementos da lista.

### Exercício 10:

Usando a Linguagem C:

a. Como você definiria o tipo fila usando a representação de lista simplesmente encadeada? Considere, para isto, uma fila de pacientes de uma clínica médica contendo os campos nome, idade, enfermidade.
b. Desenvolva a função void fila_inicializa (CELULA** inicio, CELULA** fim)
c. Desenvolva a função void fila_insereFim (CELULA** inicio, CELULA** fim, Paciente x)
d. Na função main() crie uma variável do tipo Fila. Em seguida chame a função fila_inicializa e fila_insereFim.

### Exercício 11:

Desenvolva um programa para distribuição de senhas para o atendimento em um consultório, que conta com uma única secretária e um único médico. Supondo que não há desistências, seu programa deve apoiar as seguintes situações: (a) Ao chegar no consultório, o paciente vai até a secretária e recebe uma senha numérica para ser atendido. (b) Quando o médico fica disponível para atender a um novo paciente, a secretária chama o paciente que está há mais tempo na fila.

### Exercício 12:

Escreva um programa em Linguagem C que forneça o maior, o menor e a média aritmética dos elementos de uma fila.

## Deque Dinâmica
### Exercício 13:

Um deque é basicamente uma fila de duas extremidades onde é possível inserir e remover elementos nos dois extremos da fila. Codifique, compile e execute um programa que implemente as operações de inserção e remoção do TAD deque usando os conceitos de lista duplamente encadeada formada por caracteres. Utilize a notação ponteiro para ponteiro:

a. Inserir um elemento no início da deque;
b. Remover um elemento do início da deque;
c. Inserir um elemento no final da deque;
d. Remover um elemento do final da deque;
e. Exibir elementos da deque.

## Trabalhos

*sem trabalhos nesse conteúdo*
