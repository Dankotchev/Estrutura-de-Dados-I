/*
    EXERCÍCIO 06:
    Marcos Paulo, como todo amante de filmes, sempre sonhou com uma televisão grande para suas sessões
    de cinema no final de semana. A televisão que tinha em casa, 14 polegadas, foi adquirida na época
    da faculdade e o acompanhou em várias etapas de sua vida profissional: graduação, mestrado, primeiro
    emprego. Sem falar que, graças a ela, ele se tornou fluente em inglês, pois as legendas pequenas
    eram difíceis de acompanhar durante os filmes. Após passar em um concurso federal, ele recebeu de
    presente dos pais uma televisão de 50 polegadas que o deixou bastante feliz e satisfeito.
    Uma de suas manias ao assistir televisão é pegar o controle remoto e ficar pulando de canal em
    canal sem, na verdade, assistir nenhum programa (mania esta que causava bastante irritação na esposa).
    Desenvolva uma aplicação usando o conceito de lista simplesmente encadeada circular que permita
    cadastrar os canais da operadora CTBC de TV a cabo (ex: Fox, Megapix, Universal, GNT, SBT, etc)
    e ilustre a mania de Marcos Paulo. Lembrando que o controle de Marcos Paulo veio com problemas e
    só permitia que ele passasse os canais para frente, nunca para trás.

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
    struct sCTBC *next;
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
    exibir = lista;

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

void mudarCanal(NOH **lista)
{
    if (*lista != NULL)
        *lista = (*lista)->next;
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
            inserir->next = inserir;
        else
        {
            inserir->next = (*lista)->next; // Novo nó aponta para onde o ultimo nó apontava, ou seja, o primeiro nó da lista
            (*lista)->next = inserir;
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
    printf("\n3 -\tMudar Canal de TV");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
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
            mudarCanal(&lista);
            mostrarCanalAtual(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
