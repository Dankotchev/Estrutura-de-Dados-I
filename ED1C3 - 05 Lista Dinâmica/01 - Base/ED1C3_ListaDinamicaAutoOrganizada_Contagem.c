/*
    EXERCÍCIO "Contagem":
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
    int acessos;
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
        printf("%d (%d)\t", auxiliar->info, auxiliar->acessos);
        auxiliar = auxiliar->next;
    }
    printf("\n");
}

CELULA *inserirFim(CELULA *lista, int x)
{
    CELULA *inserir;
    CELULA *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->acessos = 0;
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
        // lista = ordenar(lista);
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

CELULA *ordenar(CELULA *lista) // Ainda não está ok
{
    CELULA *atual, *anterior, *proximo, *aux;

    atual = lista;
    // Segundo nível da organização, avançando uma posição a frente a cada iteração
    while (atual != NULL)
    {
        aux = lista;
        anterior = NULL;
        proximo = aux->next;

        if (aux->next == NULL)
        {
            return lista;
        }
        else
        {
            // Primeiro nível de organização, troca de apenas um unico valor de posição
            while (proximo != NULL && (aux->acessos < proximo->acessos))
            {
                anterior = aux;
                aux = proximo;
                proximo = aux->next;
            }
            if (anterior == NULL) // Se acontecer na primeira posição da lista
            {
                anterior = proximo->next;
                proximo->next = aux;
                aux->next = anterior;
                lista = proximo;
            }
            else if (proximo != NULL) // Acontecer a partir da segunda posição
            {
                anterior->next = proximo;
                aux->next = proximo->next;
                proximo->next = aux;
            }
        }
        atual = atual->next;
    }
    return lista;
}

CELULA *buscarValorC(CELULA *lista, int x)
{
    CELULA *buscarMover;
    CELULA *auxiliar, *anterior;

    if ((buscarMover = pesquisar(lista, x)) != NULL)
    {
        buscarMover->acessos++;
        lista = ordenar(lista);
        exibirLista(lista);
        return lista;
    }
    printf("\nErro, valor nao encontrado na lista.");
    return NULL;
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE LISTAS DINAMICAS AUTO-ORGANIZADAS");
    printf("\n\t\tMETODO DE BUSCA: Contagem");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir valores na Lista;");
    printf("\n2 -\tBuscar um valor na Lista e Apresentar a Lista;");
    printf("\n3 -\tExibir a Lista completa;");
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
            printf("\nInsercao na Lista.\n");
            lista = inserirFim(lista, leituraValor());
            break;

        case 2:
            printf("\nBuscar e Apresentar um valor da Lista.\n");
            lista = buscarValorC(lista, leituraValor());
            break;

        case 3:
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
