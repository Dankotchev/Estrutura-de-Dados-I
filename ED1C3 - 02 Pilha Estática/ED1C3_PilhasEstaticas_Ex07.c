/*
    EXERCÍCIO 07:
    Dada uma pilha contendo números inteiros quaisquer, codifique uma função que coloca os pares
    na base da pilha e os ímpares no topo da pilha. Usar duas pilhas como auxiliares.
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

void pilha_Imprimir(PILHA *umaPilha)
{
    printf(" _____________\n");
    for (int i = umaPilha->topo; i >= 0; i--)
    {
        printf("|    %-5d    |\n", umaPilha->itens[i]);
        printf("|-------------|\n");
    }
}

// Demais funções

void preencher_Pilha(PILHA *umaPilha, int quantidade)
{
    int valores;
    if (quantidade > TM)
    {
        quantidade = TM;
        printf("Reajustando o valor informado para o maximo (%d) valores que a pilha aceita.\n", TM);
    }

    for (int i = 0; i < quantidade; i++)
    {
        valores = rand() % 250;
        push(umaPilha, valores);
    }
}

//Recebe a pilha original vazia, uma pilha auxiliar e empilha elementos da auxiliar na original
void organizar_PilhaInserir(PILHA *originalPilha, PILHA *auxPilha)
{
    while (!pilha_Vazia(auxPilha))
    {
        push(originalPilha, pop(auxPilha));
    }
}


//Recebe a pilha original, e separa em duas pilhas auxiliares diferentes
void organizar_Pilha(PILHA *originalPilha)
{
    PILHA pilhaPares, pilhaImpares;
    int valor;
    pilha_Inicializar(&pilhaPares);
    pilha_Inicializar(&pilhaImpares);

    // Primeira Etapa: Separar valores e duas pilhas diferentes
    while (!pilha_Vazia(originalPilha))
    {
        valor = pop(originalPilha);
        if (valor % 2 == 0)
        {
            push(&pilhaPares, valor);
        }
        else
        {
            push(&pilhaImpares, valor);
        }
    }

    // Segunda Etapa: Reunir valores na pilha original seguindo a regra
    organizar_PilhaInserir(originalPilha, &pilhaPares);
    organizar_PilhaInserir(originalPilha, &pilhaImpares);
}

int main()
{
    srand(time(NULL));
    PILHA pilhaGeral;
    int quantidade;

    pilha_Inicializar(&pilhaGeral);

    printf("Informe quantos valores deseja empilhar na pilha: ");
    scanf("%d", &quantidade);
    preencher_Pilha(&pilhaGeral, quantidade);

    printf("\nA pilha tem a seguinte forma e valores: \n");
    pilha_Imprimir(&pilhaGeral);

    printf("\nOrdenando a pilha...\n\tValores PARES em baixo da pilha;\n\tValores IMPARES acima na pilha.");
    organizar_Pilha(&pilhaGeral);
    printf("\nA pilha organizada conforme a regra tem a seguinte forma e valores: \n");
    pilha_Imprimir(&pilhaGeral);

    return 0;
}
