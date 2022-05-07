/*
    EXERCÍCIO 07:
    Codifique, compile e execute um programa em Linguagem C que permita fazer as seguintes operações
    sobre uma lista linear simplesmente encadeada formada por elementos do tipo char usando a notação
    de ponteiro para ponteiro somente quando for realmente necessário:
        ​a) inserir um elemento no início da lista;
        ​b) inserir um elemento no final do lista;
        ​c) remover um elemento do início da lista;
        d) remover um elemento do final da lista;
        e) exibir os elementos da lista.
    **Observação:** Defina funções para cada operação, incluindo uma função menu.

    Autor: Danilo Domingues Quirino
    Versão: 2205.06
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int valor;
    struct sCell *esq, *dir;
} NOH;

void init(NOH **inicio)
{
    *inicio = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void inserirInicio(NOH **lista, int x)
{
    NOH *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;
        inserir->esq = NULL;
        inserir->dir = NULL;
        if (!empty(*lista)) 
        {
            (*lista)->esq = inserir;
            inserir->dir = *lista;
        }
        *lista = inserir;
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

void inserirFim(NOH **lista, int x)
{
    NOH *inserir, *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;
        inserir->esq = NULL;
        inserir->dir = NULL;

        if (empty(*lista))
        {
            *lista = inserir;
        }
        else
        {
            auxiliar = *lista;
            while (auxiliar->dir != NULL)
                auxiliar = auxiliar->dir;

            inserir->esq = auxiliar;
            auxiliar->dir = inserir;
        }
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

int removerInicio(NOH **lista)
{
    int valor;
    NOH *remover;

    if (!empty(*lista))
    {
        remover = *lista;    
        valor = remover->valor;   
        *lista = (*lista)->dir;
        if (!(*lista == NULL))
            (*lista)->esq = NULL;
        freeNode(remover);
    }
    else
    {
        return NULL;
    }
    return valor;
}

int removerFim(NOH **lista)
{
    int valor;
    NOH *remover, *auxiliar;

    if (!empty(*lista))
    {

        if ((*lista)->dir == NULL)
        {
            remover = *lista;
            valor = remover->valor;
            *lista = NULL;
        }
        else
        {
            auxiliar = *lista;
            while (auxiliar->dir != NULL)
                auxiliar = auxiliar->dir;

            remover = auxiliar;
            valor = remover->valor;

            (auxiliar->esq)->dir = NULL;
        }
        freeNode(remover);
    }
    else
    {
        return NULL;
    }

    return valor;
}

void exibir(NOH *lista)
{
    if (!empty(lista))
    {
        while (lista != NULL)
        {
            printf("%d\t", lista->valor);
            lista = lista->dir;
        }
        printf("\n");
    }
    else
    {
        printf("Erro, lista vazia.\n");
    }
}

int lerValor()
{
    int v;
    scanf("%d", &v);
    return v;
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERACAO DE LISTA DUPLAMENTE ENCADEADA DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valor no Inicio da Lista");
    printf("\n2 -\tInserir valor no Fim da Lista");
    printf("\n3 -\tRemover valor do Inicio da Lista");
    printf("\n4 -\tRemover valor do Fim da Lista");
    printf("\n5 -\tApresentar a Lista");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 5);
    return op;
}

int main()
{
    NOH *lista;
    int op;
    int valor;

    init(&lista);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\tInserir valor no Inicio da Lista::\nInforme o Valor: ");
            inserirInicio(&lista, lerValor());
            break;

        case 2:
            printf("\n\tInserir valor no Fim da Lista::\nInforme o Valor: ");
            inserirFim(&lista, lerValor());
            break;

        case 3:
            printf("\n\tRemover valor do Inicio da Lista ::\n");
            valor = removerInicio(&lista);
            if (valor != NULL)
                printf("Valor removido: %d.\n", valor);
            else
                printf("Erro, lista vazia.\n");
            break;

        case 4:
            printf("\n\tRemover valor do Fim da Lista ::\n");
            valor = removerFim(&lista);
            if (valor != NULL)
                printf("Valor removido: %d.\n", valor);
            else
                printf("Erro, lista vazia.\n");
            break;

        case 5:
            printf("\n\tApresentar a Lista ::\n");
            exibir(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
