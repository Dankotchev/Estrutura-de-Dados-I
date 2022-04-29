/*
    EXERCÍCIO 05:
    Desenvolva uma função para testar se uma fila F1 tem mais elementos do que uma fila F2
    (não se esqueça de manipular as filas através de suas operações queue e dequeue).
    Codifique um programa que seja capaz de testar a função desenvolvida.

    Autor: Danilo Domingues Quirino
    Versão: 2203.18
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void enqueue(FILA *f, int x)
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

void imprimirFila(FILA *f)
{
    int i = (f->inicio + 1) % TM;
    if (!verificarFila(f))
    {
        printf("\nA forma da fila eh a seguinte:\n");
        while (i != ((f->fim + 1) % TM))
        {
            printf("%d ", f->itens[i]);
            i = (i + 1) % TM;
        }
    }
    else
    {
        printf("\nErro. Pilha Vazia.");
    }
}

int comprimentoFila(FILA *f) // Adaptação da função imprimir sem desenfilerar
{
    int i = (f->inicio + 1) % TM;
    int qnt = 0;
    if (!verificarFila(f))
    {
        while (i != ((f->fim + 1) % TM))
        {
            qnt++;
            // printf("%d ", f->itens[i]); Verificar se realmente possui valores na fila
            i = (i + 1) % TM;
        }
    }
    else
    {
        printf("\nErro. Pilha Vazia.");
    }
    return qnt;
}

int compararFilas(FILA *f1, FILA *f2)
{
    int a, b;

    a = comprimentoFila(f1);
    b = comprimentoFila(f2);

    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void preencherFila(FILA *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        enqueue(f, rand() % 10);
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE FILAS ESTATICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na fila F1;");
    printf("\n2 -\tInserir elementos na fila F2;");
    printf("\n3 -\tComparar Filas;");
    printf("\n4 -\tImpressao: Fila F1;");
    printf("\n5 -\tImpressao: Fila F2;");
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
    srand(time(NULL));
    FILA filaF1, filaF2;
    int opcao;

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir elementos na fila F1.");
            printf("\nUma fila F1 foi criada e preenchida com um numero aleatorio de elementos.\n");
            fila_Inicializar(&filaF1);
            preencherFila(&filaF1, rand() % (TM - 1));
            break;

        case 2:
            printf("\nInserir elementos na fila F2.");
            printf("\nUma fila F2 foi criada e preenchida com um numero aleatorio de elementos.\n");
            fila_Inicializar(&filaF2);
            preencherFila(&filaF2, rand() % (TM - 1));
            break;

        case 3:
            printf("\nComparar filas.");
            switch (compararFilas(&filaF1, &filaF2))
            {
            case 1:
                printf("\nFila F1 maior que a fila F2.");
                break;

            case 2:
                printf("\nFila F1 menor que a fila F2.");
                break;

            default:
                printf("\nFila F1 e fila F2 possuem a mesma quantidade de elementos.");
                break;
            }
            break;

        case 4:
            printf("\nImpressao da fila F1:\n\tA Fila F1 possuiu %d elementos", comprimentoFila(&filaF1));
            imprimirFila(&filaF1);
            break;

        case 5:
            printf("\nImpressao da fila F2:\n\tA Fila F2 possuiu %d elementos", comprimentoFila(&filaF2));
            imprimirFila(&filaF2);
            break;
        }
    } while (opcao != 0);

    return 0;
}
