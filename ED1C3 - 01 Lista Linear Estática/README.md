# Lista de Exercícios: Lista Linear Estática

## Exercício 01:

Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre  uma lista linear estática de números inteiros positivos:

(a) inserir um elemento em uma posição específica;

(b) remover um elemento de uma posição específica;

(c) acessar um elemento de uma posição específica;

(d) procurar um determinado elemento.

(e) exibir os elementos do vetor

Quantos bytes seu programa principal ocupa para armazenar dados?

## Exercício 02:
Desenvolva um programa em Linguagem C que permita ao usuário inserir e remover elementos nos extremos de uma sequência de itens, ou seja, no início e no final de uma lista linear estática.
## Exercício 03:
Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre uma lista linear estática de números reais: inserir um elemento mantendo a ordem crescente entre os elementos no vetor; remover um valor indicado pelo usuário, eliminando eventuais “lacunas abertas” com a remoção.
>Para que a entrada de um novo elemento ainda mantivesse a ordem crescente dentro da lista, resolvi inserir este novo elemento na última posição, e desta forma em seguida comparar a última posição da fila, com o valor de uma posição i (dentro de um laço for, percorrendo toda a lista) e se o valor recém inserido for menor que o desta posição, realiza uma troca de elementos, e as seguintes verificações são apenas para reordenar a lista.
## Exercício 04:
Desenvolva um programa em Linguagem C que possua uma função que, dada duas listas, L1 e L2, concatene L1 com L2 armazenando o resultado em L1.
> Nos exercícios 04 e 05, optei por uma lista de caracteres **MAIÚSCULOS** e **minúsculos** para uma visualização ainda mais clara do que acontece após o processamento dos dados.
> A inserção de dados nos dois exercícios sempre reiniciam a lista.
## Exercício 05:
Desenvolva um programa em Linguagem C que possua uma função que, dada duas listas, L1 e L2, intercale os elementos de L1 com L2 armazenando o resultado em uma terceira lista L3.
## Exercício 06:
Desenvolva um programa em Linguagem C que dada uma lista L1 seu inverso seja armazenado em uma lista L2.
## Exercício 07:
Na cidade de Presidente Epitácio o carnaval é uma festa que conta com a participação de um grande número de foliões, incluindo moradores da cidade e visitantes de outras localidades. A festa acontece na orla da cidade, que é ocupada por barracas para venda de bebidas, lanches e artigos em geral. Para garantir o sucesso da festa, a prefeitura define, todos os anos, um número máximo de barracas que poderão ser instaladas no local da festa. Para o ano de 2019 foi prevista a instalação de 50 barracas, as quais serão alugadas pelos comerciantes interessados. Porém, todo ano a prefeitura apresenta dificuldades para gerenciar informações como, por exemplo:

- número de barracas ocupadas e livres;
- dados do locatário (nome, CPF);
- situação dos aluguéis (pagos ou não);
- produtos que serão comercializados. 

Para facilitar o gerenciamento dessas  informações a prefeitura contratou os serviços de uma empresa de TI para desenvolver um programa na linguagem C que atenda as seguintes requisições, utilizando os conceitos de lista estática:

​		a) Todas as barracas deverão possuir uma identificação, bem como o nome e CPF do locatário responsável pelo aluguel, situação do aluguel (pago ou não), identificação do produto que será comercializado (1: bebida, 2: lanches, 3: artigos em geral);

​		b) O aluguel de barracas deverá acontecer por ordem de chegada, ou seja, o comerciante que  chegar primeiro ficará com a primeira barraca, o que chegar na sequência ficará com a segunda barraca e assim por diante;

​		c) Ao solicitar o aluguel de uma barraca, o locatário deverá fornecer ao funcionário da prefeitura as informações necessárias para cadastro (item (a));

​		d) O sistema deverá ser capaz de gerar os seguintes relatórios:

​			i)  Relatório com os dados dos locatários inadimplentes (pessoas que não efetuaram o pagamento da reserva) exibindo a identificação da barraca;

​			ii) Relatório exibindo a lista de barracas livres e ocupadas (pelo número de identificação de cada barraca apresentando ao final de cada listagem a soma total.

