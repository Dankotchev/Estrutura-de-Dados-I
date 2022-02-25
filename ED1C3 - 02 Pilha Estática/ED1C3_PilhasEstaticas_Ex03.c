/*
    EXERCÍCIO 03:
    Codifique, compile e execute um programa que seja capaz de ler do usuário diversos números e,
    para cada um destes, realizar as seguintes operações:
        a. se positivo, inserir na pilha P;
        b. se negativo, inserir na pilha N;
        c. se zero, retirar um elemento de cada pilha.
    Obs: Devem ser declaradas duas pilhas N e P que sejam capazes de armazenar valores positivos e
    negativos, respectivamente.

    Autor: Danilo Domingues Quirino
    Versão: 2202.23
*/

#include <stdio.h>
#include <ctype.h>
#define TM 100

typedef struct sPilha
{
    int itens[TM];
    int topo;
} PILHA;

// Funções referentes a Pilha
void pilha_inicializar(PILHA *umaPilha)
{
    umaPilha->topo = -1;
}

int pilha_cheia(PILHA *umaPilha)
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

int pilha_vazia(PILHA *umaPilha)
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
    if (pilha_cheia(umaPilha))
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
    if (pilha_vazia(umaPilha))
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

// Demais Funções

void pilha_ImprimirSemDesempilhar(PILHA *umaPilha)
{
    printf(" _____________\n");
    for (int i = umaPilha->topo; i >= 0; i--)
    {
        printf("|    %-5d    |\n", umaPilha->itens[i]);
        printf("|-------------|\n");
    }
}

int lerInteiro()
{
    int x;
    printf("Digite um valor: ");
    scanf("%d", &x);
    return x;
}

int main()
{

    PILHA pilhaP, pilhaN;
    pilha_inicializar(&pilhaP);
    pilha_inicializar(&pilhaN);

    char continuar;
    int valores;

    do
    {
        printf("Informe valores inteiros positivos, negativos ou zero.\n");
        valores = lerInteiro();
        if (valores > 0)
        {
            printf("Valor positivo, empilhando na pilha P.\n");
            push(&pilhaP, valores);
        }
        else if (valores < 0)
        {
            printf("Valor negativo, empilhando na pilha N.\n");
            push(&pilhaN, valores);
        }
        else
        {
            printf("Zero. Desempilhando um valor de ambas pilhas.\n");
            valores = pop(&pilhaP);
            valores = pop(&pilhaN);
        }

        printf("\nContinuar a insercao de valores?\n\tDigite \"S\" - Sim\n\tDigite \"N\" - Nao\n\t==> ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);

    } while (continuar != 'N');

    printf("\n\nInsercao de valores encerrada.\nImprimindo as pilhas.\n");
    printf("Pilha P :: \n");
    pilha_ImprimirSemDesempilhar(&pilhaP);
    printf("Pilha N :: \n");
    pilha_ImprimirSemDesempilhar(&pilhaN);

    return 0;
}
