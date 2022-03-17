# Lista de Exercícios

## Exercício 01:

Uma pilha implementa o mecanismo de inserção/remoção:
	a. FIFO 

​	b. FIFA

​	**c. LIFO** `==> Resposta correta.`

​	d. FFLL

​	e. N.D.A.  

## Exercício 02:
Codifique, compile e execute um programa que seja capaz de ler 15 números informados pelo usuário e proceda, para cada um deles, como segue:

​	a. se o número for par, insira-o na pilha;

​	b. se o número lido for ímpar, retire um número da pilha;

​	c. Ao final, esvazie a pilha imprimindo os elementos.

## Exercício 03:
Escreva uma função que devolva o comprimento (ou seja, o número de elementos) de uma determinada fila estática circular.    

## Exercício 04:
Escreva um programa em Linguagem C que seja capaz de inverter a ordem dos elementos de uma fila utilizando uma pilha como estrutura auxiliar.  

## Exercício 05:
Desenvolva uma função para testar se uma fila F1 tem mais elementos do que uma fila F2 (não se esqueça de manipular as filas através de suas operações queue e dequeue).
Codifique um programa que seja capaz de testar a função desenvolvida.  

## Exercício 06:
Escreva um programa em Linguagem C que forneça o maior, o menor e a média aritmética dos elementos de uma fila.  

## Exercício 07:
Rafinha dos Teclados é um grande admirador de música e tocador nato de teclado. Desde muito novo seus pais o incentivavam a aprimorar cada vez  mais o seu talento. Chegou a ganhar dinheiro na cidade que mora, mas levar os teclados de um lugar para outro sempre foi uma coisa que o incomodava. Com isso, ele teve a ideia de começar a tocar violão por ser um instrumento de fácil manuseio. Ele resolveu comprar uma Pasta Catálogo (com 100 plásticos) para guardar as letras das músicas que ele imprimia (uma letra/folha por plástico). Para cada nova música que ele queria aprender ele imprimia a letra e a colocava na pasta sempre após a última folha inserida. Para selecionar as letras de músicas em uma apresentação ele adotou a seguinte estratégia: cantar a música que estava no início (a que estava há mais tempo sem ser cantada) e em seguida retirá-la da pasta, recolocando-a após a última folha de música da pasta. Caso não houvesse mais espaço para inclusão de uma folha no final da pasta (a música que Rafinha acabou de cantar), ele recomeçava e colocava as folhas no início da pasta. Ele repetia este processo, cantando e remanejando as músicas enquanto alguém pedisse pra ele cantar uma nova música.  

Para esse cenário, pede-se:

a. Qual a estrutura mais adequada para solucionar o problema acima? (mencionar e detalhar o nome completo da estrutura) Justifique sua resposta;  

b. Há um limite de músicas que Rafinha pode cantar em uma determinada apresentação? Se sim, qual? Justifique sua resposta.  

c. Codifique uma estrutura que seja capaz de armazenar o nome da música e seu gênero (sertanejo, pop, rock, infantil, pagode, etc.);  

d. Codifique uma estrutura de dados, conforme sugerida no item a), para armazenamento dessas músicas, utilizando a estrutura criada no item b); 

e. Utilizando as estruturas de dados criadas, faça um desenho para representar o estado da estrutura para cada uma das etapas descritas abaixo: 

i. Pasta Catálogo vazia;

ii. Armazenamento das seguintes letras de música/gênero: - Ilariê/infantil; \- Ai Se Eu Te Pego/sertanejo; - Paparazzi/pop; - Céu Azul/rock; - Tá Vendo Aquela Lua/pagode. 

iii. Após cantar duas músicas;

iv. Armazenamento das seguintes letras de música/gênero: - ABC/infantil; Beautiful Day/rock.

v. Após cantar mais uma música;

vi. Após cantar mais uma música.

f. Codifique, compile e execute um programa que seja capaz de simular o item e) apresentado anteriormente.  

## Exercício 08:

Desenvolva um programa em Linguagem C que contenha todas as funções básicas apresentadas em sala de aula para uma estrutura de dados do tipo Pilha e que seja capaz de executar as funções solicitadas nos três últimos exercícios.

**Observação:** Crie um menu para interação com o usuário.  

# Trabalhos

## Trabalho 01

Considerando um programa em linguagem C que armazene em uma pilha P os seguintes dados: nome, idade e sexo. A partir desta pilha, codifique uma função que seja capaz de gerar duas outras pilhas: PF e PM, contendo, cada uma: nome e idade, sendo que a pilha PF armazena dados das pessoas femininas e a pilha PM das masculinas. Após este processo, exiba o conteúdo das duas pilhas.
