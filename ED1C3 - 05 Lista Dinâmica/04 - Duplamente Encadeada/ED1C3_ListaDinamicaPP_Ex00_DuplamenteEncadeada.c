/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que implemente um lista
    duplamente encadeada.
    CÓDIGO DE ESTUDO: ALTERAÇÕES CONSTANTES

    Autor: Danilo Domingues Quirino
    Versão: 2205.07
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
        inserir->esq = NULL; // Ambos ponteiros são inicializados como NULL
        inserir->dir = NULL; //
        if (!empty(*lista))  // Verificar se tem elementos na lista
        {
            (*lista)->esq = inserir; // O primeiro elemento aponta, pela esq, para o inserir
            inserir->dir = *lista;   // O elemento inserir aponta, pela dir, para o "primeiro" elemento
        }
        *lista = inserir; // Ponteiro da lista apontando para o inserir
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
        remover = *lista;         // Remover recebe o ponteiro do inicio
        valor = remover->valor;   //
        *lista = (*lista)->dir;   // Lista aponta agora para o segundo valor (que pode ser NULL)
        if (!(*lista == NULL))    // Se ainda existir valores na lista
            (*lista)->esq = NULL; // Primeiro elemento da lista agora aponta, pela esq, para NULL
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

            (auxiliar->esq)->dir = NULL; // A posição anterior a última celula na lista recebe NULL
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

NOH *pesquisar(NOH *lista, int x)
{
    NOH *procurar;

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

int removerValor(NOH **lista, int x)
{
    NOH *remover;
    int removido;

    if ((remover = pesquisar(*lista, x)) != NULL)
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
    else
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
    printf("\n6 -\tBuscar e Remover um valor");
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

        case 6:
            printf("\n\tBuscar e Remover valor ::\nInforme o valor: ");
            valor = removerValor(&lista, lerValor());
            if (valor == 1)
                printf("Valor removido.\n");
            else
                printf("Valor nao encontrado na lista.\n");
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
