/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que implemente um fila dinâmica.

    Autor: Danilo Domingues Quirino
    Versão: 2205.05
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int valor;
    struct sCell *next;
} NOH;

void init(NOH **inicio, NOH **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *filaPointer)
{
    if (filaPointer == NULL)
        return 1;
    return 0;
}

void enqueue(NOH **inicio, NOH **fim, int x)
{
    NOH *inserir;
    inserir = getNode();
    if(inserir != NULL)
    {
        inserir->valor = x;
        inserir->next = NULL;

        if (empty(*inicio))
            *inicio = inserir;

        else
            (*fim)->next = inserir;
        *fim = inserir;
    }
    else
    {
        printf("Erro na alocacao do no.\n");
        return;
    }
}

int dequeue (NOH **inicio, NOH **fim)
{
    NOH *remover;
    int x;

    if(!empty(*inicio))
    {
        remover = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;

        x = remover->valor;
        freeNode(remover);
    }
    else
    {
        printf("Erro, fila vazia.\n");
        return NULL;
    }
    return x;
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
    printf("\n----------\n\tOPERACAO DE FILA DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valor;");
    printf("\n2 -\tRemover valor;");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    }
    while (op < 0 || op > 2);
    return op;
}

int main()
{
    NOH *inicio, *fim;
    int op;

    init(&inicio,&fim);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\tInserir Valor ::\nInforme o Valor: ");
            enqueue(&inicio,&fim, lerValor());
            break;

        case 2:
            printf("\n\tRemover Valor ::\nValor removido: %d", dequeue(&inicio, &fim));
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    }
    while (op != 0);
    return 0;
}
