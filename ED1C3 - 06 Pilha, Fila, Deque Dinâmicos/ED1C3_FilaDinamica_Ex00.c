/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que implemente um fila dinâmica.

    Autor: Danilo Domingues Quirino
    Versão: 2205.03
*/

#include <ctype.h>
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
        if (empty(*inicio))
        {
            *inicio = inserir;
            *fim = inserir;
        }
        else
        {
            (*fim)->next = inserir;
            inserir->next = NULL;
            *fim = inserir;
        }
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
        if (*inicio == *fim)
        {
            remover = *fim;
            *fim = NULL;
            *inicio = NULL;
        }
        else
        {
            remover = *inicio;
            *inicio = (*inicio)->next;

        }
        x = remover->valor;
        freeNode(remover);
    }
    else {
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
    printf("\n3 -\tApresentar o primeiro da fila;");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    }
    while (op < 0 || op > 3);
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

        case 3:
            printf("\n\tApresentar a Lista ::\n");
            //exibir(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    }
    while (op != 0);
    return 0;
}
