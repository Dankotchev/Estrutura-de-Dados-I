/*
    EXERCÍCIO 00:
    Crie um arquivo e implementar as seguintes informação de uma lista linear dinâmica:
        * init
        * getnode
        * freenode
        * vazia
        * exibe_lista
        * insere_inicio, insere_fim
        * remove_inicio, remove_valor
        * pesquisa

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

CELULA *removerInicio(CELULA *lista)
{
    CELULA *remover;

    remover = lista;
    if (!listaVazia(lista))
    {
        lista = remover->next;
        freeNode(remover);
        return lista;
    }
    else
    {
        printf("Erro, lista vazia.");
        return NULL;
    }
}

CELULA *removerFim(CELULA *lista)
{
    CELULA *remover;
    CELULA *anterior;

    if (!listaVazia(lista))
    {
        remover = lista;
        while (remover->next != NULL)
        {
            anterior = remover;
            remover = remover->next;
        }
        anterior->next = NULL;
        freeNode(remover);
        return lista;
    }
    else
    {
        printf("\nErro, lista vazia");
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

CELULA *removerValor(CELULA *lista, int x)
{
    CELULA *remover;
    CELULA *auxiliar;

    if ((remover = pesquisar(lista, x)) != NULL)
    {
        auxiliar = lista;
        if (auxiliar == remover)
        {
            lista = removerInicio(lista);
            return lista;
        }

        else
        {
            while (auxiliar->next != remover)
                auxiliar = auxiliar->next;
            auxiliar->next = remover->next;
            freeNode(remover);
        }
        return lista;
    }
    return NULL;
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE LISTAS DINAMICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir valores no Inicio da Lista;");
    printf("\n2 -\tInserir valores no Fim da lista;");
    printf("\n3 -\tRemover valores no Inicio da Lista;");
    printf("\n4 -\tRemover valores no Fim da Lista;");
    printf("\n5 -\tRemover um valor especifico da Lista;");
    printf("\n6 -\tExibir a Lista completa;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    return opcao;
}

int leituraValor()
{
    int v;
    printf("\nInforme um valor :: ");
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
            printf("\nRemocao de valores a partir do Inicio da Lista.\n");
            lista = removerInicio(lista);
            break;

        case 4:
            printf("\nRemocao de valores a partir do Fim da Lista.\n");
            lista = removerFim(lista);
            break;

        case 5:
            printf("\nRemover um valor especifico da lista.\n");
            lista = removerValor(lista, leituraValor());
            break;

        case 6:
            printf("\nExibir a lista.\n");
            exibirLista(lista);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
