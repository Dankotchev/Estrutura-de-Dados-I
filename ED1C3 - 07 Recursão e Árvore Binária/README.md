# Lista de Exercícios 1
## Recursão
### Exercício 01:

Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre uma lista simplesmente encadeada:

a. Calcular o comprimento da lista;

b. Somar todos os elementos da lista;

c. Multiplicar todos os elementos da lista;

d. Imprimir os elementos ímpares a partir do início da lista;

e. Imprimir os elementos pares da lista na ordem inversa.

**Observação** Para cada operação acima desenvolva uma função recursiva. Desenvolva também uma função menu para que o usuário possa selecionar a opção desejada.

## Árvores Binárias
### Exercício 02:

Desenvolva um programa em linguagem C que implemente as seguintes funções recursivas para uma árvore binária:

a. Inserir um nó;

b. Exibir a árvore em Pré-Ordem;

c. Exibir a árvore em Em-Ordem;

d. Exibir a árvore em Pós-Ordem;

e. Calcular o número de nós;

f. Calcular o número de folhas;

g. Calcular a altura.

# Lista de Exercícios 2
## Exercícios de Resolução Gráfica
### Exercício 01:

Quais são as sequências de nós encontradas ao atravessar a árvore abaixo em emordem, pré-ordem e pós-ordem?

<a href="https://imgbox.com/n21uFE0X" target="_blank"><img src="https://images2.imgbox.com/dc/08/n21uFE0X_o.png" alt="Arvore Binaria"/></a>



### Exercício 02:
Considerando uma árvore de busca com n nós, qual é a relação entre o número de comparações (entre a chave procurada e chaves em nós) e a altura da árvore?

### Exercício 03:
Insira os números 35, 39, 51, 20, 13, 28, 22, 32, 25, 33 (nesta ordem) em uma árvore AVL, demonstrando, passo a passo, a inserção de cada elemento com as respectivas rotações, caso seja necessário.

### Exercício 04: 
Dê um exemplo de inserção de um elemento em uma árvore AVL que cause rearranjo da estrutura da árvore.

### Exercício 05:
Dê um exemplo de remoção de um elemento de uma árvore AVL que cause rearranjo da estrutura da árvore.

### Exercício 06:
Por que nos damos ao trabalho de procurar trabalhar com árvores binárias balanceadas? Justifique.

## Exercícios de Resolução em linguagem C
### Exercício 07:

Num sistema de arquivos, um catálogo de todos os arquivos é organizado como uma árvore de busca binária. Cada nó denota um arquivo e especifica seu nome e, entre outras coisas, a data de seu último acesso, codificada como um inteiro. Escreva um programa que percorra a árvore e apague todos os arquivos cujos últimos acessos tenham sido anteriores a uma certa data. As chaves do catálogo são os nomes dos arquivos.

### Exercício 08:
Codifique um programa que contenha uma função recursiva que verifique se uma árvore binária está balanceada.

### Exercício 09:
Utilizando o exercício anterior como base, escreva uma função que seja capaz de computar o número de nós ancestrais em uma árvore binária para um dado nó a um nível K.