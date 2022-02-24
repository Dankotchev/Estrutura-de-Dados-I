/*
    EXERCÍCIO 06:
    Codifique uma função que troque de lugar o elemento que está no topo de uma pilha de caracteres
    com o que está na base da pilha. Usar apenas uma pilha como auxiliar e, caso necessário,
    variáveis do tipo char.

    Autor: Danilo Domingues Quirino
    Versão: 2202.23
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TM 100

typedef struct sPilha
{
    char itens[TM];
    int topo;
} PILHA;

// Funções referentes a Pilha
void pilha_Inicializar(PILHA *umaPilha)
{
    umaPilha->topo = -1;
}

int pilha_Cheia(PILHA *umaPilha)
{
    if (umaPilha->topo == TM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_Vazia(PILHA *umaPilha)
{
    if (umaPilha->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(PILHA *umaPilha, int x)
{
    if (pilha_Cheia(umaPilha))
    {
        printf("\nErro: Pilha cheia.");
    }
    else
    {
        umaPilha->topo++;
        umaPilha->itens[umaPilha->topo] = x;
    }
}

int pop(PILHA *umaPilha)
{
    int x;
    if (pilha_Vazia(umaPilha))
    {
        printf("\nErro: Pilha Vazia.");
    }
    else
    {
        x = umaPilha->itens[umaPilha->topo];
        umaPilha->topo--;
        return x;
    }
}

void pilha_Imprimir(PILHA *umaPilha)
{
    printf(" _____________\n");
    for (int i = umaPilha->topo; i >= 0; i--)
    {
        printf("|    %-5d    |\n", umaPilha->itens[i]);
        printf("|-------------|\n");
    }
}

int main()
{
    srand(time(NULL));
    PILHA pilhaP;

    pilha_Inicializar(&pilhaP);

    return 0;
}
