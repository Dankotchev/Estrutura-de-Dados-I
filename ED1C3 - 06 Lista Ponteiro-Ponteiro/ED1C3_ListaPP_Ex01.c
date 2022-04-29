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
    CELULA *auxiliar;

    auxiliar = lista;
    while (auxiliar != NULL)
    {
        printf("%d\t", auxiliar->info);
        auxiliar = auxiliar->next;
    }
    printf("\n");
}

void inserirInicio(CELULA **lista, int x)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = x;
        inserir->next = *lista;
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

void inserirFim(CELULA **lista, int x)
{
    CELULA *inserir;
    CELULA *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = x;
        inserir->next = NULL;

        if (listaVazia(*lista))
        {
            *lista = inserir;
        }
        else
        {
            auxiliar = *lista;
            while (auxiliar->next != NULL)
                auxiliar = auxiliar->next;
            auxiliar->next = inserir;
        }
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
        *lista = remover->next;
    }
    else
    {
        printf("Erro, lista vazia.");
        exit(1);
    }
}

void removerFim(CELULA **lista)
{
    CELULA *remover;
    CELULA *anterior;

    if (!listaVazia(*lista))
    {
        remover = *lista;
        while (remover->next != NULL)
        {
            anterior = remover;
            remover = remover->next;
        }
        anterior->next = NULL;
        freeNode(remover);
    }
    else
    {
        printf("\nErro, lista vazia");
        exit(1);
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

int removerValor(CELULA **lista, int x)
{
    CELULA *remover;
    CELULA *auxiliar;

    if ((remover = pesquisar(*lista, x)) != NULL)
    {
        auxiliar = *lista;
        if (auxiliar == remover)
        {
            removerInicio(lista);
        }

        else
        {
            while (auxiliar->next != remover)
                auxiliar = auxiliar->next;
            auxiliar->next = remover->next;
            freeNode(remover);
        }
        return 1;
    }
    return 0;
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
    inicializar(&lista);
    int opcao;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\nInsercao no Inicio da Lista.\n");
            inserirInicio(&lista, leituraValor());
            break;

        case 2:
            printf("\nInsercao no Fim da Lista.\n");
            inserirFim(&lista, leituraValor());
            break;

        case 3:
            printf("\nRemocao de valores a partir do Inicio da Lista.\n");
            removerInicio(&lista);
            break;

        case 4:
            printf("\nRemocao de valores a partir do Fim da Lista.\n");
            removerFim(&lista);
            break;

        case 5:
            printf("\nRemover um valor especifico da lista.\n");
            if (removerValor(&lista, leituraValor()))
                printf("Valor Removido.\n");
            else
                printf("Valor nao Removido.\n");
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
