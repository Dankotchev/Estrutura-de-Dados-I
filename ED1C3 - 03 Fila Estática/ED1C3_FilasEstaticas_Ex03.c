/*
    EXERCÍCIO 03:
    CEscreva uma função que devolva o comprimento (ou seja, o número de elementos) de uma
    determinada fila estática circular.

    Autor: Danilo Domingues Quirino
    Versão: 2203.15
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

    // Verificar
    if (verificarFila(f))
    {
        printf("Erro. Fila Cheia.");
        // Se cheia, retonar fim para a posição anterior
        f->fim--;
        if (f->fim == -1)
        {
            f->fim = TM - 1;
        }
        return;
    }

    f->itens[f->fim] = x;
    // Se houver espaço, inserir elemento na fila
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

void preencherFila(FILA *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        enqueue(f, rand() % 10);
    }
}

int main()
{
    srand(time(NULL));
    FILA umaFila;
    int quantidade = rand() % (TM - 1);

    fila_Inicializar(&umaFila);

    printf("Uma fila foi criada e preenchida com um numero aleatorio de elementos.\n");
    preencherFila(&umaFila, quantidade);
    printf("O comprimento da fila eh de %d valores.\n", comprimentoFila(&umaFila));

    return 0;
}
