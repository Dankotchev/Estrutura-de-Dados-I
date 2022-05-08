/*
    EXERCÍCIO 00:
    Codifique, compile e execute um programa em Linguagem C que implemente uma função que receba
    como parâmetro uma lista linear duplamente encadeada de números reais e retorne a soma de todos
    os elementos da lista.

    Autor: Danilo Domingues Quirino
    Versão: 2205.07
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct sCell
{
    float valores;
    struct sCell *esq, *dir;
} NOH;

void init(NOH **inicio)
{
    *inicio = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

int empty(NOH *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void inserir(NOH **lista, float x)
{
    NOH *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valores = x;
        inserir->esq = NULL; // Ambos ponteiros são inicializados como NULL
        inserir->dir = NULL; //
        if (!empty(*lista))  // Verificar se tem elementos na lista
        {
            (*lista)->esq = inserir; // O primeiro elemento aponta, pela esq, para o inserir
            inserir->dir = *lista;   // O elemento inserir aponta, pela dir, para o "primeiro" elemento
        }
        *lista = inserir; // Ponteiro da lista apontando para o inserir
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

void exibir(NOH *lista)
{
    if (!empty(lista))
    {
        while (lista != NULL)
        {
            printf("%0.2f\t", lista->valores);
            lista = lista->dir;
        }
        printf("\n");
    }
    else
    {
        printf("Erro, lista vazia.\n");
    }
}

float somatorio(NOH *lista)
{
    NOH *inicio = lista;
    float somatorio = 0;

    if (!empty(lista))
    {
        somatorio += lista->valores;
        while (lista->dir != inicio)
        {
            somatorio += lista->valores;
            lista = lista->dir;
        }
    }
    else
        printf("Erro, fila vazia.\n");

    return somatorio;
    //printf("Soma valores: %0.2f.\n", somatorio);
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
    printf("\n----------\n\tOPERACAO DE LISTA DUPLAMENTE ENCADEADA DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valores na Lista");
    printf("\n2 -\tApresentar a Lista");
    printf("\n3 -\tSomatorio dos valores da Lista");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
    return op;
}

int main()
{
    NOH *lista;
    int op;
    int entradas;
    float valorAtual;

    srand(time(NULL));

    init(&lista);

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
                printf("\t[#%03d] - Inserindo na fila o numero %.2f.\n", i + 1, valorAtual);
                inserir(&lista, valorAtual);
                sleep(1);
            }
            break;

        case 2:
            printf("\tApresentar a Lista ::\n");
            exibir(lista);
            break;

        case 3:
            printf("\tSomatorio dos valores da Lista ::\nA lista vale %04.2f.\n: ", somatorio(lista));
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
