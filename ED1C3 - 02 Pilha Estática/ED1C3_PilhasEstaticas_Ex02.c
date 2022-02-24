/*
    EXERCÍCIO 02:
    Codifique, compile e execute um programa que seja capaz de ler 15 números informados pelo
    usuário e proceda, para cada um deles, como segue:
        a. se o número for par, insira-o na pilha;
        b. se o número lido for ímpar, retire um número da pilha;
        c. Ao final, esvazie a pilha imprimindo os elementos.

    Autor: Danilo Domingues Quirino
    Versão: 2202.23
*/

#include <stdio.h>
#define TM 100

typedef struct sPilha
{
    int itens[TM];
    int topo;
} PILHA;

void pilha_inicializar(PILHA *p)
{
    p->topo = -1;
}

int pilha_cheia(PILHA *p)
{
    if (p->topo == TM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_vazia(PILHA *p)
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
    if (pilha_cheia(p))
    {
        printf("\nErro: Pilha cheia");
    }
    else
    {
        p->topo++;
        p->itens[p->topo] = x;
    }
}

int pop(PILHA *p)
{
    int x;
    if (pilha_vazia(p))
    {
        printf("\nErro: Pilha Vazia");
    }
    else
    {
        x = p->itens[p->topo];
        p->topo--;
        return x;
    }
}

void pilha_imprimir(PILHA *p)
{
    int x;
    printf(" _____________\n");
    while (!pilha_vazia(p))
    {
        x = pop(p);
        printf("|    %-5d    |\n", x);
        printf("|-------------|\n");
    }
}

int main()
{

    PILHA p;
    pilha_inicializar(&p);
    int valores;

    printf("Informe os 15 valores.:");
    for (int i = 0; i < 3; i++)
    {
        printf("\n\nInforme o item %d: ", i);
        scanf("%d", &valores);
        if (valores % 2 == 0)
        {
            push(&p, valores);
            printf("Valor %d eh PAR; Foi inserido na pilha.", valores);
        }
        else
        {
            printf("Valor %d eh IMPAR; ", valores);
            valores = pop(&p);
            printf("Removendo o valor %d da pilha.", valores);
        }
    }

    printf("\n\nImprimindo todos os valores da pilha...\n");
    pilha_imprimir(&p);

    return 0;
}
