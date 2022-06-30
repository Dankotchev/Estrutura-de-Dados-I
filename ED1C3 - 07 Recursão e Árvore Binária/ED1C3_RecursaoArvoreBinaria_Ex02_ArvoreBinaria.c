/*
    EXERCÍCIO 02:
    Desenvolva um programa em linguagem C que implemente as seguintes funções recursivas para uma
    árvore binária:
        a. Inserir um nó;
        b. Exibir a árvore em Pré-Ordem;
        c. Exibir a árvore em Em-Ordem;
        d. Exibir a árvore em Pós-Ordem;
        e. Calcular o número de nós;
        f. Calcular o número de folhas;
        g. Calcular a altura.

    OBS: Defina funções para cada operação, incluindo uma função menu.

    Autor: Danilo Domingues Quirino
    Versão: 2206.20
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int valor;
    struct cell *esq;
    struct cell *dir;
} NOH;

void plantaArvore(NOH **raiz)
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

void exibirPreOrdem(NOH *raiz)
{
    if (!vazia(raiz))
    {
        printf("%d\t", raiz->valor);
        exibirPreOrdem(raiz->esq);
        exibirPreOrdem(raiz->dir);
    }
}

void exibirEmOrdem(NOH *raiz)
{
    if (!vazia(raiz))
    {
        exibirEmOrdem(raiz->esq);
        printf("%d\t", raiz->valor);
        exibirEmOrdem(raiz->dir);
    }
}

void exibirPosOrdem(NOH *raiz)
{
    if (!vazia(raiz))
    {
        exibirPosOrdem(raiz->esq);
        exibirPosOrdem(raiz->dir);
        printf("%d\t", raiz->valor);
    }
}

void inserirNoh(NOH **raiz, int x)
{
    if (vazia(*raiz))
    {
        *raiz = getNode();
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->valor = x;
    }
    else
    {
        if (x < (*raiz)->valor)
            inserirNoh(&((*raiz)->esq), x);
        else
            inserirNoh(&((*raiz)->dir), x);
    }
}

int quantidadeNohs(NOH *raiz)
{
    if (vazia(raiz))
    {
        return 0;
    }
    else
    {
        return 1 + quantidadeNohs(raiz->esq) + quantidadeNohs(raiz->dir);
    }
}

int quantidadeFolhas(NOH *raiz)
{
    if (vazia(raiz))
    {
        return 0;
    }
    else if (raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    else
        return quantidadeFolhas(raiz->esq) + quantidadeFolhas(raiz->dir);
}

int alturaArvore(NOH *raiz)
{
    if (vazia(raiz))
    {
        return -1;
    }
    else
    {
        int esquerda = alturaArvore(raiz->esq);
        int direita = alturaArvore(raiz->dir);
        if (esquerda > direita)
            return esquerda + 1;
        else
            return direita + 1;
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tRECURSIVIDADE");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na Arvore");
    printf("\n2 -\tExibir a arvore (Pre-Ordem)");
    printf("\n3 -\tExibir a arvore (Em-Ordem)");
    printf("\n4 -\tExibir a arvore (Pos-Ordem)");
    printf("\n5 -\tNumeros de noh da Arvore");
    printf("\n6 -\tNumero de folhas na Arvore");
    printf("\n7 -\tAltura da Arvore");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);
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

    NOH *arvoreBinaria;
    plantaArvore(&arvoreBinaria);
    int opcao;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\tInsercao de valores na Arvore");
            inserirNoh(&arvoreBinaria, leituraValor());
            break;

        case 2:
            printf("\tExibir a arvore (Pre-Ordem)\n");
            exibirPreOrdem(arvoreBinaria);
            break;

        case 3:
            printf("\tExibir a arvore (Em-Ordem)\n");
            exibirEmOrdem(arvoreBinaria);
            break;

        case 4:
            printf("\tExibir a arvore (Pos-Ordem)\n");
            exibirPosOrdem(arvoreBinaria);
            break;

        case 5:
            printf("\n\tA Arvore contem %d noh.\n", quantidadeNohs(arvoreBinaria));
            break;

        case 6:
            printf("\n\tA Arvore contem %d folhas.\n", quantidadeFolhas(arvoreBinaria));
            break;

        case 7:
            printf("\n\tA altura da Arvore eh de %d.\n", alturaArvore(arvoreBinaria));
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
