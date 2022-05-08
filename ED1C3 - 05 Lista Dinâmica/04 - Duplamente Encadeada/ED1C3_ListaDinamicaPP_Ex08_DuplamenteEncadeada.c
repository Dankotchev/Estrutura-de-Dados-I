/*
    EXERCÍCIO 08:
    Marcos Paulo irritado com o controle remoto de sua televisão que só passava os canais em uma
    direção, resolveu ligar na garantia do produto solicitando um novo controle remoto que funcionasse
    corretamente (capaz de percorrer em duas direções,‘aumentar’ e ‘diminuir’ os canais). Utilizando
    como base a implementação do exercício 6), codifique, compile e execute uma nova aplicação que
    seja capaz de percorrer os canais com o novo controle remoto. Para isso, utilize o conceito de
    lista linear duplamente encadeada circular.

    Autor: Danilo Domingues Quirino
    Versão: 2205.07
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define TCANAL 30

typedef struct sCanal
{
    int numCanal;
    char nomeCanal[TCANAL];
} CHANEL;

typedef struct sCTBC
{
    CHANEL canal;
    struct sCTBC *esq, *dir;
} NOH;

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void init(NOH **lista)
{
    *lista = NULL;
}

void freeNode(NOH *no)
{
    free(no);
}

int listaVazia(NOH *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void mostrarCanalAtual(NOH *lista)
{
    NOH *exibir;
    exibir = lista->dir;

    if (exibir != NULL)
    {
        printf("Canal n# %03d - %s\t", exibir->canal.numCanal, exibir->canal.nomeCanal);
    }
    else
    {
        printf("Erro, lista de Canais vazia.\n");
    }
    printf("\n");
}

void mudarCanalAumentar(NOH **lista)
{
    if (*lista != NULL)
        *lista = (*lista)->dir;
    else
        printf("Erro, lista de Canais vazia.\n");
}

void mudarCanalDiminuir(NOH **lista)
{
    if (*lista != NULL)
        *lista = (*lista)->esq;
    else
        printf("Erro, lista de Canais vazia.\n");
}

void inserirCanal(NOH **lista, CHANEL canal)
{
    NOH *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->canal = canal;

        if (listaVazia(*lista))
        {
            inserir->dir = inserir;
            inserir->esq = inserir;
        }
        else
        {
            inserir->dir = (*lista)->dir; // Novo nó aponta para onde o ultimo nó apontava, ou seja, o primeiro nó da lista
            inserir->esq = *lista;
            (*lista)->dir = inserir;
            inserir->dir->esq = inserir;
        }
        *lista = inserir;
    }
    else
    {
        printf("Erro na insercao de novos canais.\n");
        return;
    }
}

CHANEL lerInfoCanal(int x)
{
    CHANEL canal;

    canal.numCanal = x;
    printf("Canal # %03d.\n", x);
    printf("Digite o nome do canal: ");
    // fflush(stdin);
    __fpurge(stdin);
    fgets(canal.nomeCanal, TCANAL, stdin);
    if (canal.nomeCanal[strlen(canal.nomeCanal) - 1] == '\n')
    {
        canal.nomeCanal[strlen(canal.nomeCanal) - 1] = '\0';
    }

    return canal;
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tLISTA DE CANAIS DE TELEVISAO DA CTBC");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tMostrar Canal Atual");
    printf("\n2 -\tAdicionar Canal de TV");
    printf("\n3 -\tMudar Canal (Aumentar) de TV");
    printf("\n4 -\tMudar Canal (Diminuir) de TV");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 4);
    return op;
}

int main()
{
    NOH *lista;
    int numCanal = 1;
    int op;

    init(&lista);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tCanal atual :: \n");
            mostrarCanalAtual(lista);
            break;

        case 2:
            printf("\tAdicionar Canal :: \n");
            inserirCanal(&lista, lerInfoCanal(numCanal));
            numCanal++;
            break;

        case 3:
            printf("\tMudar de Canal ::\n");
            mudarCanalAumentar(&lista);
            mostrarCanalAtual(lista);
            break;

        case 4:
            printf("\tMudar de Canal ::\n");
            mudarCanalDiminuir(&lista);
            mostrarCanalAtual(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
