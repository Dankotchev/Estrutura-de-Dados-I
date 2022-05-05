/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que implemente um lista
    duplamente encadeada.

    Autor: Danilo Domingues Quirino
    Versão: 2205.03
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int valor;
    struct sCell *esq, *dir;
} CELL;

void init(CELL **inicio)
{
    *inicio = NULL;
}

CELL *getNode()
{
    return (CELL *)malloc(sizeof(CELL));
}

void freeNode(CELL *no)
{
    free(no);
}

int empty(CELL *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void inserirInicio(CELL **lista, int x) // NÃO INSERE SE LISTA VAZIA
{
    CELL *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;
        inserir->esq = NULL;     // Ninguem a esquerda do inserir
        inserir->dir = *lista;   // A direita do inserir, posição inicial inicio anterior
        (*lista)->esq = inserir; // O antigo primeiro, apontando para o inserir
        *lista = inserir;        // Ponteiro da lista apontando para o inserir
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

void inserirFim(CELL **lista, int x)
{
    CELL *inserir, *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;

        if (empty(*lista))
        {
            inserir->esq = NULL;
            inserir->dir = NULL;
            *lista = inserir;
        }
        else
        {
            auxiliar = *lista;
            while (auxiliar->dir != NULL)
                auxiliar = auxiliar->dir;

            inserir->esq = auxiliar;
            inserir->dir = NULL;
            auxiliar->dir = inserir;
        }
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

int removerInicio(CELL **lista) // NÃO REMOVE SE LISTA COM AO MENOS UM
{
    int valor;
    CELL *remover;

    if (!empty(*lista))
    {
        remover = *lista;       // Remover recebe o ponteiro do inicio
        valor = remover->valor; //
        *lista = remover->dir;  // Lista aponta agora para o segundo valor (que pode ser NULL)
        (*lista)->esq = NULL;   // Primeiro elemento da lista agora aponta para NULL
        freeNode(remover);
    }
    else
    {
        printf("Erro, lista vazia.\n");
        return NULL;
    }
    return valor;
}

int removerFim(CELL **lista)
{
    int valor;
    CELL *remover, *auxiliar;

    if (!empty(*lista))
    {

        if ((*lista)->dir == NULL)
        {
            remover = *lista;
            valor = remover->valor;
            *lista = NULL;
            freeNode(remover);
        }
        else
        {
            auxiliar = *lista;
            while (auxiliar->dir != NULL)
                auxiliar = auxiliar->dir;

            remover = auxiliar;
            valor = remover->valor;

            (auxiliar->esq)->dir = NULL; // A posição anterior a última celula na lista recebe NULL
            freeNode(remover);
        }
    }
    else
    {
        printf("Erro, lista vazia.\n");
        return NULL;
    }

    return valor;
}

CELL *pesquisar(CELL *lista, int x)
{
    CELL *procurar;

    if (!empty(lista))
    {
        procurar = lista;
        while (procurar != NULL)
        {
            if (procurar->valor == x)
                return procurar;
            procurar = procurar->dir;
        }
    }
    return NULL;
}

void exibir(CELL *lista)
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

int removerValor(CELL **lista, int x)
{
    CELL *remover;
    int removido;

    if (remover = pesquisar(*lista, x) != NULL)
    {
        if (*lista == remover)
            removerInicio(lista);
        else
        {
            (*remover->esq).dir = remover->dir;   // Celula anterior ao remover, aponta para a próxima celula
            if (remover->dir != NULL)             // Se o elemnto a ser removido não for o último da lista
                remover->dir->esq = remover->esq; // A próxima celula, aponta para a celúla anterior ao remover

            freeNode(remover);
        }
        removido = 1;
    }
    removido = 0;
    return removido;
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
    printf("\n6 -\tABuscar e Remover um valor");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 6);
    return op;
}

int main()
{
    CELL *lista;
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
            if (valor = removerInicio(&lista) != NULL)
                printf("Valor removido: %d.\n", valor);
            printf("Erro, lista vazia.\n");
            break;

        case 4:
            printf("\n\tRemover valor do Fim da Lista ::\n");
            if (valor = removerFim(&lista) != NULL)
                printf("Valor removido: %d.\n", valor);
            printf("Erro, lista vazia.\n");
            break;

        case 5:
            printf("\n\tApresentar a Lista ::\n");
            exibir(lista);
            break;

        case 6:
            printf("\n\tBuscar e Remover valor ::\nInforme o valor: ");
            if (removerValor(&lista, lerValor()) == 1)
                printf("Valor removido.\n");
            printf("Valor nao encontrado na lista.\n");

            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
