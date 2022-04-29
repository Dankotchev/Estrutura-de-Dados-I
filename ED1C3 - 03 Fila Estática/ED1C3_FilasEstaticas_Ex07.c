/*
    EXERCÍCIO 07:
    Rafinha dos Teclados é um grande admirador de música e tocador nato de teclado. Desde muito novo
    seus pais o incentivavam a aprimorar cada vez  mais o seu talento. Chegou a ganhar dinheiro na
    cidade que mora, mas levar os teclados de um lugar para outro sempre foi uma coisa que o incomodava.
    Com isso, ele teve a ideia de começar a tocar violão por ser um instrumento de fácil manuseio.
    Ele resolveu comprar uma Pasta Catálogo (com 100 plásticos) para guardar as letras das músicas
    que ele imprimia (uma letra/folha por plástico). Para cada nova música que ele queria aprender
    ele imprimia a letra e a colocava na pasta sempre após a última folha inserida. Para selecionar as
    letras de músicas em uma apresentação ele adotou a seguinte estratégia: cantar a música que estava
    no início (a que estava há mais tempo sem ser cantada) e em seguida retirá-la da pasta, recolocando-a
    após a última folha de música da pasta. Caso não houvesse mais espaço para inclusão de uma folha
    no final da pasta (a música que Rafinha acabou de cantar), ele recomeçava e colocava as folhas no
    início da pasta. Ele repetia este processo, cantando e remanejando as músicas enquanto alguém
    pedisse pra ele cantar uma nova música.

    Para esse cenário, pede-se:
        a) Qual a estrutura mais adequada para solucionar o problema acima?
        (mencionar e detalhar o nome completo da estrutura) Justifique sua resposta;
​		b) Há um limite de músicas que Rafinha pode cantar em uma determinada apresentação?
        Se sim, qual? Justifique sua resposta.
​		c) Codifique uma estrutura que seja capaz de armazenar o nome da música e seu gênero
        (sertanejo, pop, rock, infantil, pagode, etc.);
​		d) Codifique uma estrutura de dados, conforme sugerida no item a), para armazenamento dessas
        músicas, utilizando a estrutura criada no item b);
​		e) Utilizando as estruturas de dados criadas, faça um desenho para representar o estado da
        estrutura para cada uma das etapas descritas abaixo:
            i) Pasta Catálogo vazia;
            ii) Armazenamento das seguintes letras de música/gênero:
                - Ilariê/infantil;
                - Ai Se Eu Te Pego/sertanejo;
                - Paparazzi/pop;
                - Céu Azul/rock;
                - Tá Vendo Aquela Lua/pagode.
            iii) Após cantar duas músicas;
            iv) Armazenamento das seguintes letras de música/gênero:
                    - ABC/infantil;
                    - Beautiful Day/rock.
            v) Após cantar mais uma música;
            vi) Após cantar mais uma música.
        f) Codifique, compile e execute um programa que seja capaz de simular o item e) apresentado anteriormente.

    Autor: Danilo Domingues Quirino
    Versão: 2203.20
*/

#include <stdio.h>
#include <string.h>
#define TM 100
#define TC 50
#define TG 20

typedef struct sMusicas
{
    char nomeCancao[TC];
    char genero[TG];
} FOLHA;

typedef struct sfila
{
    FOLHA plastico[TM];
    int inicio, fim;
} PASTA;

void inicializar(PASTA *ctlg)
{
    ctlg->inicio = TM - 1;
    ctlg->fim = TM - 1;
}

int verificarFila(PASTA *ctlg)
{
    if (ctlg->inicio == ctlg->fim)
        return 1;
    return 0;
}

void enqueue(PASTA *ctlg, FOLHA new)
{
    // Incrementar
    if (ctlg->fim == (TM - 1))
    {
        ctlg->fim = 0;
    }
    else
    {
        ctlg->fim++;
    }

    if (verificarFila(ctlg))
    {
        printf("Erro. Fila Cheia.");
        ctlg->fim--;
        if (ctlg->fim == -1)
        {
            ctlg->fim = TM - 1;
        }
        return;
    }

    ctlg->plastico[ctlg->fim] = new;
}

FOLHA dequeue(PASTA *ctlg)
{
    if (!verificarFila(ctlg))
    {
        if (ctlg->inicio == TM - 1)
        {
            ctlg->inicio = 0;
        }
        else
        {
            ctlg->inicio++;
        }
    }
    else
    {
        printf("Erro. Fila Vazia");
    }
    return ctlg->plastico[ctlg->inicio];
}

void imprimirPasta(PASTA *ctlg)
{
    int i = (ctlg->inicio + 1) % TM;
    if (!verificarFila(ctlg))
    {
        printf("\nA pasta catalago contem as seguintes musicas:\n");
        while (i != ((ctlg->fim + 1) % TM))
        {
            printf("%s / %s\n", ctlg->plastico[i].nomeCancao, ctlg->plastico[i].genero);
            i = (i + 1) % TM;
        }
        printf("\n");
    }
    else
    {
        printf("\nErro. Pilha Vazia.");
    }
}

void lerTexto(char *texto, int tamanho)
{
    fflush(stdin);
    fgets(texto, tamanho, stdin);
    if (texto[strlen(texto) -1] == '\n')
    {
        texto[strlen(texto) - 1] = '\0';
    }
}

void inserirElementosFila(PASTA *ctlg)
{
    FOLHA musicaNova;
    int continuar;

    do
    {

        printf("\nInforme o Titulo da Musica: ");
        lerTexto(musicaNova.nomeCancao, TC - 1);
        printf("Informe o Genero Musical: ");
        lerTexto(musicaNova.genero, TG - 1);

        enqueue(ctlg, musicaNova);

        if (!verificarFila(ctlg))
        {
            printf("\nDeseja inserir um outra musica?\n\t1 - SIM\n\t0 - NAO");
            do
            {
                printf("\n\tEscolha ==>   ");
                scanf("%d", &continuar);
            } while (continuar < 0 || continuar > 1);
        }

    } while (continuar != 0);
}

FOLHA cantarMusica(PASTA *ctlg)
{
    FOLHA cantar;

    cantar = dequeue(ctlg); // Remover a primeira folha e tocar cantar a musica
    enqueue(ctlg, cantar);    // Realocar a musica cantada para a ultima posição da pasta
    return cantar;
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tPASTA CATALAGO DE RAFINHA DOS TECLADOS (VIOLEIRO)");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir nova Musica na pasta;");
    printf("\n2 -\tCantar uma Musica;");
    printf("\n3 -\tLista das Musicas na pasta;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
    return opcao;
}

int main()
{
    PASTA catalago;
    FOLHA cancao;
    int opcao;

    inicializar(&catalago);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir nova Musica na Pasata Catalago.");
            inserirElementosFila(&catalago);
            break;

        case 2:
            printf("\nCantar uma Musica.");
            cancao = cantarMusica(&catalago);
            printf("\nA musica cantada foi:\n\t%s / %s\n", cancao.nomeCancao, cancao.genero);
            break;

        case 3:
            printf("\nListar as Musicas da Pasta Catalago.");
            imprimirPasta(&catalago);
            break;

        case 0:
            printf("\nENCERRANDO O SISTEMA.");
            break;
        }
    } while (opcao != 0);

    return 0;
}