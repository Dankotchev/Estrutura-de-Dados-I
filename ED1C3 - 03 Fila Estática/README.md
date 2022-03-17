# Lista de Exercícios

## Exercício 01:

Imagine uma implementação circular de uma fila em um vetor fila[0..9] que contém:
16 17 18 19 20 11 12 13 14
Suponha que o primeiro elemento da fila está na posição de índice 5 e o último está na posição de índice 3. Essa fila está cheia?  
`Se o primeiro elemento se encontra na posição de indice 5, a variavel ínico se encontra então na posição anterior, logo, na posição 4. o ulimo elemento estando no índice 3, a váriavél fim, também e encorntra na posição 4. Portanto, se ínicio e fim são iguais a fila encontra-se cheia neste momento.`


## Exercício 02:
Uma pilha implementa o mecanismo de inserção/remoção:
	**a. FIFO** `==> Resposta correta.`

​	b. FIFA

​	c. LIFO

​	d. FFLL

​	e. N.D.A.  

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

​		a) Qual a estrutura mais adequada para solucionar o problema acima? (mencionar e detalhar o nome completo da estrutura) Justifique sua resposta;  

​		b) Há um limite de músicas que Rafinha pode cantar em uma determinada apresentação? Se sim, qual? Justifique sua resposta.  

​		c) Codifique uma estrutura que seja capaz de armazenar o nome da música e seu gênero (sertanejo, pop, rock, infantil, pagode, etc.);  

​		d) Codifique uma estrutura de dados, conforme sugerida no item a), para armazenamento dessas músicas, utilizando a estrutura criada no item b); 

​		e) Utilizando as estruturas de dados criadas, faça um desenho para representar o estado da estrutura para cada uma das etapas descritas abaixo: 

​				i) Pasta Catálogo vazia;

​				ii) Armazenamento das seguintes letras de música/gênero: - Ilariê/infantil; \- Ai Se Eu Te Pego/sertanejo; - Paparazzi/pop; - Céu Azul/rock; - Tá Vendo Aquela Lua/pagode. 

​				iii) Após cantar duas músicas;

​				iv) Armazenamento das seguintes letras de música/gênero: - ABC/infantil; Beautiful Day/rock.

​				v) Após cantar mais uma música;

​				vi) Após cantar mais uma música.

​		f) Codifique, compile e execute um programa que seja capaz de simular o item e) apresentado anteriormente.  

## Exercício 08 (Desafio):

Uma das grandes conquistas dos cidadãos brasileiros que possuem idade superior a 60 anos foi a criação da Lei nº 10.741, de 1º de outubro de 2003, que traz em seu texto a regulamentação do Estatuto do Idoso. Dentre os vários  Direitos assegurados, o Artigo nº 40 menciona o direito a vagas em transportes rodoviários interestaduais, sendo assegurado 2 vagas gratuitas por veículo e o restante com desconto de 50% para aqueles que comprovarem ter direito ao benefício e ser de baixa renda. Entretanto, várias empresas de transporte rodoviário não fazem esse controle e liberam a entrada de idosos em seus veículos, desde que seja realizado o embarque e desembarque pela porta da frente (em veículos que possuem duas portas de acesso). Nesses casos, os
demais passageiros embarcam apenas pela porta de trás e sempre  desembarcam pela porta da frente. A "Empresa TransPass" é uma das empresas que cumpre essa lei e que disponibiliza uma linha de ônibus (com capacidade máxima de 40 passageiros) que faz o transporte de passageiros entre Presidente Epitácio e Presidente Prudente. A cada viagem, os passageiros podem embarcar em qualquer um dos pontos de parada ao longo do caminho, seja pela porta dianteira ou pela porta traseira, de acordo com a sua idade. Entretanto, o desembarque é realizado somente na cidade de destino, o qual é realizado pela porta dianteira do ônibus, seja na cidade de Presidente Epitácio ou de Presidente Prudente.  

Posto este cenário, pede-se:  

​		a) Qual a estrutura mais adequada para solucionar o problema acima? (mencionar e detalhar o nome completo da estrutura) Justifique sua resposta; 

​		b) Codifique uma estrutura que seja capaz de armazenar o nome de uma pessoa e sua idade; 

​		c) Codifique uma uma estrutura de dados, conforme sugerida no item a), para armazenamento dessas pessoas, utilizando a estrutura criada no item b); 

​		d) Utilizando as estruturas de dados criadas, faça um desenho para representar o
estado da estrutura para cada uma das etapas descritas abaixo: 

​				i) Ônibus vazio;

​				ii) Cidade de origem: Presidente Epitácio 

​				iii) Passageiros para embarque na seguinte sequência: - Bart, 20 anos; Lisa: 19 anos; Homer Simpson: 62 anos; Marge: 65 anos; Maggie: 15 anos. 

​				iv) Ponto de parada: Presidente Venceslau

​				v) Passageiros para embarque na seguinte sequência: - Papai Smurf, 70 anos; - Smurfette: 18 anos; - Desastrado: 25 anos; - Preguiça: 30 anos; Vovô Smurf, 95 anos. 

​				vi) Ponto de parada: Santo Anastácio

​				vii) Passageiros para embarque na seguinte sequência: - Bob Esponja, 10 anos; - Patrick, 12 anos; - Seu Serigueijo, 62 anos.

​				viii) Cidade de destino: Presidente Prudente. Todos os passageiros para  desembarque

​		e) Codifique, compile e execute um programa que seja capaz de simular o item d) apresentado anteriormente.

# Trabalhos

*sem trabalhos nesse conteúdo*
