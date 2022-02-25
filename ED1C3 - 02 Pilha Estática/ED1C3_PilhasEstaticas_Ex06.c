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

void push(PILHA *umaPilha, char x)
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

char pop(PILHA *umaPilha)
{
    char x;
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

void trocarTopoBase(PILHA *p)
{
    PILHA s;
    pilha_Inicializar(&s);
    char auxA, auxB;

    auxA = pop(p);
    while (p->topo != 0)
    {
        push(&s, pop(p));
    }
    auxB = pop(p);
    push(p, auxA);
    while (!pilha_Vazia(&s))
    {
        push(p, pop(&s));
    }
    push(p, auxB);
}

void ImprimirSemDesempilhar(PILHA *umaPilha)
{
    printf("\n __________\n");
    for (int i = umaPilha->topo; i >= 0; i--)
    {
        printf("|    %c    |\n", umaPilha->itens[i]);
        printf("|---------|\n");
    }
}

int main()
{
    srand(time(NULL));
    PILHA p;
    int quantidade;

    pilha_Inicializar(&p);

    printf("Informe quantos valores deseja empilhar na pilha P: ");
    scanf("%d", &quantidade);
    if (quantidade > TM)
    {
        quantidade = TM;
        printf("Reajustando o valor informado para o maximo (%d) valores que a pilha aceita.\n", TM);
    }

    for (int i = 0; i < quantidade; i++)
    {
        push(&p, (97 + rand() % 26));
    }

    printf("\nA pilha P tem a seguinte forma e caracteres: \n");
    ImprimirSemDesempilhar(&p);
    printf("\nTrocando o caracter do Topo pelo da Base temos a seguinte pilha ...");
    trocarTopoBase(&p);
    ImprimirSemDesempilhar(&p);

    return 0;
}
