/*
    EXERCÍCIO 04:
    Escreva um programa em Linguagem C que seja capaz de inverter a ordem dos elementos de uma fila
    utilizando uma pilha como estrutura auxiliar.

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

typedef struct sPilha
{
    int itens[TM];
    int topo;
} PILHA;

void pilha_Inicializar(PILHA *p)
{
    p->topo = -1;
}

int pilha_Cheia(PILHA *p)
{
    if (p->topo == (TM - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_Vazia(PILHA *p)
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(PILHA *p, int x)
{
    if (!pilha_Cheia(p))
    {
        p->topo++;
        p->itens[p->topo] = x;
    }
    else
    {
        printf("Erro: Pilha Cheia");
    }
}

int pop(PILHA *p)
{
    int x;
    if (!pilha_Vazia(p))
    {
        x = p->itens[p->topo];
        p->topo--;
        return x;
    }
    else
    {
        printf("Erro: Pilha Vazia");
    }
    return x;
}

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

int dequeue (FILA *f)
{
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
    }
    else
    {
        printf("Erro. Fila Vazia");
    }

    return f->itens[f->inicio];
}

void imprimirFila(FILA *f)
{
    int i = (f->inicio + 1) % TM;
    if (!verificarFila(f))
    {
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

void preencherFila(FILA *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        queue(f, rand() % 10);
    }
}

void inverterFila(FILA *f)
{
    PILHA aux;
    pilha_Inicializar(&aux);

    while (!verificarFila(f))
    {
        push(&aux, dequeue(f));
    }

    while (!pilha_Vazia(&aux))
    {
        queue(f, pop(&aux));
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

    printf("\nA fila atualmente tem a seguinte forma:\n");
    imprimirFila(&umaFila);

    printf("\nInvertendo a fila...");
    inverterFila(&umaFila);

    printf("\nA fila invertida tem a seguite forma:\n");
    imprimirFila(&umaFila);

    return 0;
}
