/*
    EXERCÍCIO 12:
    Escreva um programa em Linguagem C que forneça o maior, o menor e a
    média aritmética dos elementos de uma fila.

    Autor: Danilo Domingues Quirino
    Versão: 2205.06
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
    if (inserir != NULL)
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

float dequeue(NOH ***inicio, NOH ***fim)
{
    NOH *remover;
    float x;

    if (!empty(**inicio))
    {
        remover = **inicio;
        **inicio = (**inicio)->next;
        if (**inicio == NULL)
            **fim = NULL;

        x = remover->valor;
        freeNode(remover);
    }
    else
    {
        printf("Erro, fila vazia.\n");
        return;
    }
    return x;
}

void mediaMaiorMenor(NOH *inicio, NOH *fim)
{
    float menor, maior, somatorio = 0, media;
    int qtd = 0;
    float valorAtual;

    if (!empty(inicio))
    {
        valorAtual = inicio->valor;
        maior = valorAtual;
        menor = valorAtual;
        somatorio += valorAtual;
        while (inicio != NULL)
        {
            valorAtual = inicio->valor;
            somatorio += valorAtual;
            qtd++;

            if (maior < valorAtual)
                maior = valorAtual;
            if (menor > valorAtual)
                menor = valorAtual;

            inicio = inicio->next;
        }
    }
    else
        printf("Erro, fila vazia.\n");

    media = somatorio / qtd;
    printf("Menor valor: %0.2f.\n", menor);
    printf("Maior valor: %0.2f.\n", maior);
    printf("Media valores: %0.2f.\n", media);
    printf("Soma valores: %0.2f.\n", somatorio);
}

int lerValor()
{
    int v;
    scanf("%d", &v);
    return v;
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
    } while (op < 0 || op > 2);
    return op;
}

int main()
{
    NOH *inicio, *fim;
    int op, entradas;
    float valorAtual;

    srand(time(NULL));

    init(&inicio, &fim);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInsercao de Valores na fila :: \tInformes quantos valores inserir: ");
            entradas = lerValor();
            for (int i = 0; i < entradas; i++)
            {
                valorAtual = ((float)rand() / (float)(RAND_MAX)) * 100;
                printf("\tInserindo na fila o numero %.2f.\n", valorAtual);
                enqueue(&inicio, &fim, valorAtual);
                sleep(1);
            }
            break;

        case 2:
            mediaMaiorMenor(inicio, fim);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
