/*
    EXERCÍCIO 01:
    Codifique, compile e execute um programa em Linguagem C que permita fazer as
    seguintes operações sobre uma lista linear simplesmente encadeada formada por
    elementos do tipo char usando a notação de ponteiro para ponteiro somente quando
    for realmente necessário:
        a. Inserir um elemento no início da lista;
        b. Inserir um elemento no final da lista;
        c. Remover um elemento do início da lista;
        d. Remover um determinado elemento da lista;
        e. Exibir os elementos da lista.

    OBS: Defina funções para cada operação, incluindo uma função menu.

    Autor: Danilo Domingues Quirino
    Versão: 2204.14
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    char letra;
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
        printf("%c\t", lista->letra);
        lista = lista->next;
    }
    printf("\n");
}

void inserirInicio(CELULA **lista, char a)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->letra = a;
        inserir->next = *lista;
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

void inserirFim(CELULA **lista, char a)
{
    CELULA *inserir;
    CELULA *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->letra = a;
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

CELULA *pesquisar(CELULA *lista, char a)
{
    CELULA *procurar;

    if (!listaVazia(lista))
    {
        procurar = lista;
        while (procurar != NULL)
        {
            if (procurar->letra == a)
                return procurar;
            procurar = procurar->next;
        }
    }
    return NULL;
}

int removerValor(CELULA **lista, char a)
{
    CELULA *remover;
    CELULA *auxiliar;

    if ((remover = pesquisar(*lista, a)) != NULL)
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
    printf("\n1 -\tInserir caracter no Inicio da Lista;");
    printf("\n2 -\tInserir caracter no Fim da lista;");
    printf("\n3 -\tRemover caracter no Inicio da Lista;");
    printf("\n4 -\tRemover caracter no Fim da Lista;");
    printf("\n5 -\tRemover um caracter especifico da Lista;");
    printf("\n6 -\tExibir a Lista completa;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    return opcao;
}

char leituraCaracter()
{
    char v;
    //fflush(stdin);
    __fpurge(stdin);
    printf("\nInforme um caracter :: ");
    scanf("%c", &v);
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
            inserirInicio(&lista, leituraCaracter());
            break;

        case 2:
            printf("\nInsercao no Fim da Lista.\n");
            inserirFim(&lista, leituraCaracter());
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
            if (removerValor(&lista, leituraCaracter()))
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
