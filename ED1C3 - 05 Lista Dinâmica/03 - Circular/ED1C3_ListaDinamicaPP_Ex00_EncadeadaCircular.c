/*
    EXERCÍCIO 00:
    Crie um arquivo ListaSimplesmentEncadeadaCircular.c e
    implementa as seguintes informações de uma lista circular:
        * Definição
        * Operações
        * init
        * getnode
        * freenode
        * insere_inicio
        * listar
        * remove_inicio

    Teste seu programa criando um menu com as opções de inserir, remover e exibir.
    CÓDIGO DE ESTUDO: ALTERAÇÕES CONSTANTES

    Autor: Danilo Domingues Quirino
    Versão: 2205.07
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
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
    CELULA *exibir;

    exibir = lista->next;

    if(exibir != NULL)
    {
        do
        {
            printf("%d\t", exibir->info);
            exibir= exibir->next;
        }
        while (exibir != lista->next);
    }
    printf("\n");
}

void inserirFim(CELULA **lista, int a)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = a;

        if (listaVazia(*lista))
        {
            inserir->next = inserir;
        }
        else
        {
            inserir->next = (*lista)->next;
            (*lista)->next = inserir;
        }
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no.");
        exit(1);
    }
}

void removerInicio(CELULA **lista)
{
    CELULA *remover;

    remover = *lista;
    if (!listaVazia(*lista))
    {
        if((*lista) == (*lista)->next)
        {
            freeNode(*lista);
            *lista = NULL;
        }
        else
        {
            remover = (*lista)->next;
            (*lista)->next = remover->next;
            freeNode(remover);
        }
    }
    else
    {
        printf("Erro, lista vazia.");
        exit(1);
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE LISTAS CIRCULARES");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir na Lista;");
    printf("\n2 -\tRemover da Lista;");
    printf("\n3 -\tExibir a Lista completa;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    }
    while (opcao < 0 || opcao > 3);
    return opcao;
}

int leituraCaracter()
{
    int v;
    printf("\nInforme um valor :: ");
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
            printf("\nInserir na Lista.\n");
            inserirFim(&lista, leituraCaracter());
            break;

        case 2:
            printf("\nRemover da Lista.\n");
            removerInicio(&lista);
            break;

        case 3:
            printf("\nExibir a lista.\n");
            exibirLista(lista);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    }
    while (opcao != 0);

    return 0;
}
