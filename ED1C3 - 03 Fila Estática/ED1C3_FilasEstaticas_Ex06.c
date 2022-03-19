/*
    EXERCÍCIO 06:
    Escreva um programa em Linguagem C que forneça o maior, o menor e a média aritmética
    dos elementos de uma fila.

    Autor: Danilo Domingues Quirino
    Versão: 2203.
*/

#include <stdio.h>
#define TM 100

typedef struct sfila
{
    int itens[TM];
    int inicio, fim;
} FILA;

void fila_Inicializar(FILA *f)
{
    f->inicio = TM - 1;
    f->fim = TM - 1;
}

int verificarFila(FILA *f)
{
    if (f->inicio == f->fim)
        return 1;
    return 0;
}

void queue(FILA *f, int x)
{
    // Incrementar
    if (f->fim == (TM - 1))
    {
        f->fim = 0;
    }
    else
    {
        f->fim++;
    }

    if (verificarFila(f))
    {
        printf("Erro. Fila Cheia.");
        f->fim--;
        if (f->fim == -1)
        {
            f->fim = TM - 1;
        }
        return;
    }

    f->itens[f->fim] = x;
}

int dequeue(FILA *f)
{
    int x;

    if (!verificarFila(f))
    {
        if (f->inicio == TM - 1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
        x = f->itens[f->inicio];
    }
    else
    {
        printf("Erro. Fila Vazia");
    }
    return x;
}

int maiorValor(FILA *f)
{
    FILA auxF;
    int auxV, maior = f->itens[f->inicio];

    // Encontando o maior valor, removendo itens por itens e quardando em uma fila auxiliar
    while (!verificarFila(f))
    {
        auxV = dequeue(f);
        if (auxV > maior)
        {
            maior = auxV;
        }
        queue(&auxF, auxV);
    }

    // Devolvendo os itens da fila auxiliar para a principal
    while (!verificarFila(&auxF))
    {
        queue(f, dequeue(&auxF));
    }
    return maior;
}

int menorValor(FILA *f)
{
    FILA auxF;
    int auxV, menor = f->itens[f->inicio];

    // Encontando o menor valor, removendo itens por itens e quardando em uma fila auxiliar
    while (!verificarFila(f))
    {
        auxV = dequeue(f);
        if (auxV < menor)
        {
            menor = auxV;
        }
        queue(&auxF, auxV);
    }

    // Devolvendo os itens da fila auxiliar para a principal
    while (!verificarFila(&auxF))
    {
        queue(f, dequeue(&auxF));
    }
    return menor;
}

float mediaValor(FILA *f)
{
    int somatorio = 0, contagem = 0;
    int x;
    FILA aux;

    fila_Inicializar(&aux);

    while (!verificarFila(f))
    {
        x = dequeue(f);
        somatorio += x;
        contagem ++;
        queue(&aux, x);
    }

    while (!verificarFila(&aux))
    {
        queue(f, dequeue(&aux));
    }

    return somatorio / contagem;
    
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE FILAS ESTATICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na fila;");
    printf("\n2 -\tEncontrar o MENOR valor da fila;");
    printf("\n3 -\tEncontrar o MAIOR valor da fila;");
    printf("\n4 -\tMEDIA dos valores da fila;");
    printf("\n5 -\tImpressao da fila;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 5);
    return opcao;
}

int main()
{
    FILA f;
    int opcao;

    fila_Inicializar(&f);

    do
    {
        switch (opcao)
        {
        case 1:

            break;

        case 0:
            printf("\nENCERRANDO O SISTEMA.");
            break;
        }
    } while (opcao != 0);

    return 0;
}