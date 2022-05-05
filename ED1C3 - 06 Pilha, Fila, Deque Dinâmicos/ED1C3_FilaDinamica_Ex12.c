/*
    EXERCÍCIO 12:
    Escreva um programa em Linguagem C que forneça o maior, o menor e a
    média aritmética dos elementos de uma fila.

    Autor: Danilo Domingues Quirino
    Versão: 2205.05
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct sCell
{
    float valor;
    struct sCell *next;
} NOH;

void init(NOH **inicio, NOH **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *filaPointer)
{
    if (filaPointer == NULL)
        return 1;
    return 0;
}

void enqueue(NOH **inicio, NOH **fim, float x)
{
    NOH *inserir;
    inserir = getNode();
    if(inserir != NULL)
    {
        inserir->valor = x;
        inserir->next = NULL;

        if (empty(*inicio))
            *inicio = inserir;

        else
            (*fim)->next = inserir;
        *fim = inserir;
    }
    else
    {
        printf("Erro na alocacao do no.\n");
        return;
    }
}

float dequeue (NOH **inicio, NOH **fim)
{
    NOH *remover;
    float x;

    if(!empty(*inicio))
    {
        remover = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;

        x = remover->valor;
        freeNode(remover);
    }
    else
    {
        printf("Erro, fila vazia.\n");
        return NULL;
    }
    return x;
}



int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERACAO DE FILA DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valores na fila");
    printf("\n2 -\tMaior, Menor e Media");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    }
    while (op < 0 || op > 3);
    return op;
}



int main()
{
    NOH *inicio, *fim;
    int op;
    int senhaAtual = 1, ultSenha;

    init(&inicio,&fim);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tAtribuicao de Senha :: Senha %d atribuida.\n", senhaAtual);
            enqueue(&inicio,&fim, senhaAtual);
            senhaAtual++;
            break;

        case 2:
            ultSenha = dequeue(&inicio, &fim);
            printf("\tChamando Senha: %d\n", ultSenha);
            break;

        case 3:
            printf("\tImpressao nao classica de Fila: \n");
            /*

            printf("Estado da fila: \n");
            while (fila != NULL)
            {
            printf("%d  ", fila->senha);
            fila = fila->next;
            }
            }
            */
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    }
    while (op != 0);
    return 0;
}
