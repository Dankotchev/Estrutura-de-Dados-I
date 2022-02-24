/*
    EXERCÍCIO 05:
    Dada uma pilha P, codifique uma função que inverta a ordem dos elementos dessa pilha utilizando
    apenas uma estrutura auxiliar.
        Obs: - Defina adequadamente a estrutura auxiliar;
        - atente sobre a possibilidade da pilha estar vazia.

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
    int itens[TM];
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

void pilha_ImprimirSemDesempilhar(PILHA *umaPilha)
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
    int vetAux[TM];
    int quantidade, valores;
    pilha_Inicializar(&pilhaP);

    printf("Informe quantos valores deseja empilhar na pilha P: ");
    scanf("%d", &quantidade);
    if (quantidade > TM)
    {
        quantidade = TM;
        printf("Reajustando o valor informado para o maximo (%d) valores que a pilha aceita.\n", TM);
    }

    for (int i = 0; i < quantidade; i++)
    {
        valores = rand() % 250;
        push(&pilhaP, valores);
    }

    printf("\nA pilha P tem a seguinte forma e valores: \n");
    pilha_ImprimirSemDesempilhar(&pilhaP);

    printf("\nInvertendo a pilha P...");
    for (int i = 0; i < quantidade; i++)
    {
        vetAux[i] = pop(&pilhaP);
    }
    for (int j = 0; j < quantidade; j++)
    {
        push(&pilhaP, vetAux[j]);
    }

    printf("\nA pilha P Invertida tem a seguinte forma e valores: \n");
    pilha_ImprimirSemDesempilhar(&pilhaP);

    return 0;
}
