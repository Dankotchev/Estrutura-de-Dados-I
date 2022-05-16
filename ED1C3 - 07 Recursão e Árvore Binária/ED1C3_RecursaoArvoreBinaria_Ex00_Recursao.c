/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que permita fazer as
    seguintes operações sobre uma lista linear simplesmente encadeada formada por
    elementos do tipo char usando a notação de ponteiro para ponteiro somente quando
    for realmente necessário:
        a. Inserir um elemento no início da lista;
        b. Exibir lista na ordem direta;
        c. Exibir lista na ordem indireta;

    OBS: Defina funções para cada operação, incluindo uma função menu.

    Autor: Danilo Domingues Quirino
    Versão: 2205.16
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int valor;
    struct cell *next;
} CELULA;

void inicializar(CELULA **lista)
{
    *lista = NULL;
}

CELULA *getNode()
{
    return (CELULA *)malloc(sizeof(CELULA));
}

void freeNode(CELULA *no)
{
    free(no);
}

int listaVazia(CELULA *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void exibirLista(CELULA *lista)
{
    while (lista != NULL)
    {
        printf("%d\t", lista->valor);
        lista = lista->next;
    }
    printf("\n");
}

void exibirListaRecursao(CELULA *lista)
{
    if(lista->next != NULL)
        exibirListaRecursao(lista->next);
    printf("%d\t",lista->valor);
}



void inserirInicio(CELULA **lista, int x)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;
        inserir->next = *lista;
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tRECURSIVIDADE");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na Lista;");
    printf("\n2 -\tExibir a lista (Ordem direta);");
    printf("\n3 -\tExibir a lista (Ordem indireta);");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
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

    CELULA *lista;
    inicializar(&lista);
    int opcao;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\tInsercao de valores na Lista");
            inserirInicio(&lista, leituraValor());
            break;

        case 2:
            printf("\tExibir a lista (Ordem direta)\n");
            exibirLista(lista);
            break;

        case 3:
            printf("\tExibir a lista (Ordem indireta)\n");
            exibirListaRecursao(lista);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
