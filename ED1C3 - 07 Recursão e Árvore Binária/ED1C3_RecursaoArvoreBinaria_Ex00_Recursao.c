/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que permita fazer as seguintes operaçõeses
    sobre uma lista linear simplesmente encadeada formada por elementos do tipo char usando a notação
    de ponteiro para ponteiro somente quando for realmente necessário:
        a. Inserir um elemento no início da lista;
        b. Exibir lista na ordem direta;
        c. Exibir lista na ordem indireta;

    OBS: Defina funções para cada operação, incluindo uma função menu.

    Autor: Danilo Domingues Quirino
    Vers�o: 2206.20
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *esq;
    struct cell *dir;
} NOH;

void inicializar(NOH **raiz)
{
    *raiz = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int vazia(NOH *raiz)
{
    if (raiz == NULL)
        return 1;
    return 0;
}

void exibir(NOH *raiz)
{
    if (!vazia(raiz))
    {
        exibir(raiz->esq);
        printf("%d\t", raiz->info);
        exibir(raiz->dir);
    }
}

void inserir(NOH **raiz, int x)
{
    if(vazia(*raiz))
    {
        *raiz = getNode();
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->info = x;
    }
    else
    {
        if(x <(*raiz)->info)
            inserir(&((*raiz)->esq), x);
        else //if(x >= (*raiz)->info)
            inserir(&((*raiz)->dir), x);
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tRECURSIVIDADE");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na Arvore;");
    printf("\n2 -\tExibir a arvore (Em-Ordem);");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    }
    while (opcao < 0 || opcao > 2);
    return opcao;
}

int leituraValor()
{
    int v;
    printf("\tInforme um valor :: ");
    scanf("%d", &v);
    return v;
}

int main()
{

    NOH *raiz;
    inicializar(&raiz);
    int opcao;
    int valor;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\tInsercao de valores na Arvore");
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //inserir(&raiz, leituraValor());
            inserir(&raiz, valor);
            break;

        case 2:
            printf("\tExibir a arvore (Em Ordem)\n");
            exibir(raiz);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    }
    while (opcao != 0);

    return 0;
}
