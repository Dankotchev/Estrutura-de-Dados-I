/*
    EXERCÍCIO "Transposição":
    Implementar os seguintes métodos de busca para listas auto-organizadas:
        a) Mover para frente
        b) Transposição
        c) Contagem

    Autor: Danilo Domingues Quirino
    Versão: 2204.17
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

CELULA *inicializar(CELULA *lista)
{
    lista = NULL;
    return lista;
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
    CELULA *auxiliar;

    auxiliar = lista;
    while (auxiliar != NULL)
    {
        printf("%d\t", auxiliar->info);
        auxiliar = auxiliar->next;
    }
    printf("\n");
}

CELULA *inserirInicio(CELULA *lista, int x)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = x;
        inserir->next = lista;
        lista = inserir;
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return NULL;
    }
}

CELULA *inserirFim(CELULA *lista, int x)
{
    CELULA *inserir;
    CELULA *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = x;
        inserir->next = NULL;

        if (listaVazia(lista))
        {
            lista = inserir;
        }
        else
        {
            auxiliar = lista;
            while (auxiliar->next != NULL)
                auxiliar = auxiliar->next;
            auxiliar->next = inserir;
        }
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no.");
        return NULL;
    }
}

CELULA *pesquisar(CELULA *lista, int x)
{
    CELULA *procurar;

    if (!listaVazia(lista))
    {
        procurar = lista;
        while (procurar != NULL)
        {
            if (procurar->info == x)
                return procurar;
            procurar = procurar->next;
        }
    }
    return NULL;
}

CELULA *buscarValorT(CELULA *lista, int x)
{
    CELULA *buscarMover;
    CELULA *auxiliar, *anterior;

    if ((buscarMover = pesquisar(lista, x)) != NULL)
    {
        if(buscarMover != lista)
        {
            auxiliar = lista;
            if (auxiliar != buscarMover)
            {
                while (auxiliar->next != buscarMover)
                {
                    anterior= auxiliar;
                    auxiliar = auxiliar->next;
                }
                auxiliar->next = auxiliar->next->next;
                buscarMover->next = auxiliar;
                anterior->next = buscarMover;
            }
            exibirLista(lista);
            return lista;
        }
        exibirLista(lista);
        return lista;
    }
    else
    {
        printf("\nErro, valor nao encontrado na lista.");
        return NULL;
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE LISTAS DINAMICAS AUTO-ORGANIZADAS");
    printf("\n\t\tMETODO DE BUSCA: TRANSPOSICAO");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir valores no Inicio da Lista;");
    printf("\n2 -\tInserir valores no Fim da lista;");
    printf("\n3 -\tBuscar um valor na Lista e Apresentar a Lista;");
    printf("\n4 -\tExibir a Lista completa;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    }
    while (opcao < 0 || opcao > 4);
    return opcao;
}

int leituraValor()
{
    int v;
    printf("Informe um valor :: ");
    scanf("%d", &v);
    return v;
}

int main()
{

    CELULA *lista;
    lista = inicializar(lista);
    int opcao;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\nInsercao no Inicio da Lista.\n");
            lista = inserirInicio(lista, leituraValor());
            break;

        case 2:
            printf("\nInsercao no Fim da Lista.\n");
            lista = inserirFim(lista, leituraValor());
            break;

        case 3:
            printf("\nBuscar e Apresentar um valor da Lista.\n");
            lista = buscarValorT(lista, leituraValor());
            break;

        case 4:
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
