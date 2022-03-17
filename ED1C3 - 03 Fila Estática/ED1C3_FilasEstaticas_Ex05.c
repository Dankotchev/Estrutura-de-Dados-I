/*
    EXERCÍCIO 05:
    Desenvolva uma função para testar se uma fila F1 tem mais elementos do que uma fila F2
    (não se esqueça de manipular as filas através de suas operações queue e dequeue).
    Codifique um programa que seja capaz de testar a função desenvolvida.

    Autor: Danilo Domingues Quirino
    Versão: 2203.
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

int dequeue (FILA *f)
{
    int x;

    if (!verificarFila(f))
    {
        if (f->inicio == TM -1)
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
    while (!verificarFila(f2))
    {
        a = dequeue(f2);
        b = dequeue(f1);
    }
    
}


void preencherFila(FILA *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        queue(f, rand() % 10);
    }
}

int main()
{
    srand(time(NULL));
    FILA filaF1, filaF2;

    fila_Inicializar(&filaF1);
    fila_Inicializar(&filaF2);

    printf("Uma fila F1 foi criada e preenchida com um numero aleatorio de elementos.\n");
    preencherFila(&filaF1, rand() % (TM - 1));

    printf("Uma fila F2 foi criada e preenchida com um numero aleatorio de elementos.\n");
    preencherFila(&filaF2, rand() % (TM - 1));
    

    return 0;
}
