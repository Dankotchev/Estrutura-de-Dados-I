/*
    EXERCÍCIO 13:
    Um deque é basicamente uma fila de duas extremidades onde é possível inserir e remover elementos
    nos dois extremos da fila. Codifique, compile e execute um programa que implemente as operações
    de inserção e remoção do TAD deque usando os conceitos de lista duplamente encadeada formada por
    caracteres. Utilize a notação ponteiro para ponteiro:
        a. Inserir um elemento no início da deque;
        b. Remover um elemento do início da deque;
        c. Inserir um elemento no final da deque;
        d. Remover um elemento do final da deque;
        e. Exibir elementos da deque.

    Autor: Danilo Domingues Quirino
    Versão: 2205.06
*/
#include <ctype.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct sCell
{
    char letra;
    struct sCell *esq, *dir;
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

int empty(NOH *deque)
{
    if (deque == NULL)
        return 1;
    return 0;
}

void startEnqueue(NOH **inicio, NOH **fim, char c)
{
    NOH *inserirI;
    inserirI = getNode();
    if (inserirI != NULL)
    {
        inserirI->letra = c;
        inserirI->esq = NULL; // Ambos ponteiros apontam para NULL no inicio
        inserirI->dir = NULL;

        if (!empty(*inicio)) // Se Houver elementos na Deque
        {
            (*inicio)->esq = inserirI; // O primeiro elemento aponta, pela esq, para o inserir
            inserirI->dir = *inicio;   // O elemento inserir aponta, pela dir, para o "primeiro" elemento
        }
        else
            *fim = inserirI; // Se não houver elementos, fim aponta para inserir
        *inicio = inserirI;  // Tendo ou não elementos, inicio aponta para inserir;
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

void endEnqueue(NOH **inicio, NOH **fim, char c)
{
    NOH *inserirF;

    inserirF = getNode();
    if (inserirF != NULL)
    {
        inserirF->letra = c;
        inserirF->esq = NULL;
        inserirF->dir = NULL;

        if (!empty(*inicio)) // Se Houver elementos na Deque
        {
            (*fim)->dir = inserirF; // O ultimo elemento aponta, pela dir, para o inserir
            inserirF->esq = *fim;   // O elemento inserir aponta, pela esq, para o "ultimo" elemento
        }
        else
            *inicio = inserirF; // Se não houver elementos, inicio aponta para inserir
        *fim = inserirF;        // Tendo ou não elementos, fim aponta para inserir;
    }
    else
    {
        printf("Erro na alocacao do noh.\n");
        return;
    }
}

char startDequeue(NOH **inicio, NOH **fim)
{
    char c;
    NOH *removerI;

    if (!empty(*inicio))
    {
        removerI = *inicio;       // Remover recebe o ponteiro do inicio
        c = removerI->letra;      // c recebe char
        *inicio = (*inicio)->dir; // O primeiro elemento passa ser o segundo
        if (*inicio == NULL)      // Caso deque fique vazia, fim também será NULL
            *fim = NULL;
        else
            (*inicio)->esq = NULL; // Se a deque não ficar fazia, primeiro elemento aponta, pela esq, para NULL
        freeNode(removerI);
    }
    else
        return NULL;
    return c;
}

char endDequeue(NOH **inicio, NOH **fim)
{
    char c;
    NOH *removerF;

    if (!empty(*inicio))
    {
        removerF = *fim;     // Remover recebe o ponteiro do fim
        c = removerF->letra; // Valor recebe char
        *fim = (*fim)->esq;  // O penúltimo elemento passa ser o último
        if (*fim == NULL)    // Caso deque fique vazia, inicio também será NULL
            *inicio = NULL;
        else
            (*fim)->dir = NULL; // Se deque não ficar vazia, último elemento aponta, pela dir, para NULL
        freeNode(removerF);
    }
    else
        return NULL;
    return c;
}

void showDeque(NOH *deque)
{
    if (!empty(deque))
    {
        while (deque != NULL)
        {
            printf("%c\t", deque->letra);
            deque = deque->dir;
        }
        printf("\n");
    }
    else
        printf("Erro, deque vazia.\n");
}

char lerChar()
{
    char v;
    // fflush(stdin);
    __fpurge(stdin);
    scanf("%c", &v);
    return v;
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERACAO DE DEQUE DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir caracter no Inicio da Deque");
    printf("\n2 -\tInserir caracter no Fim da Deque");
    printf("\n3 -\tRemover caracter do Inicio da Deque");
    printf("\n4 -\tRemover caracter do Fim da Deque");
    printf("\n5 -\tApresentar a Deque");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 5);
    return op;
}

int main()
{
    NOH *inicio, *fim;
    int op;
    char letra;

    init(&inicio, &fim);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInserir caracter no Inicio da Lista::\tInforme o Caracter: ");
            startEnqueue(&inicio, &fim, lerChar());
            break;

        case 2:
            printf("\tInserir caracter no Fim da Lista::\tInforme o Caracter: ");
            endEnqueue(&inicio, &fim, lerChar());
            break;

        case 3:
            printf("\tRemover caracter do Inicio da Lista ::\t");
            letra = startDequeue(&inicio, &fim);
            if (letra != NULL)
                printf("Valor removido: %c\n", letra);
            else
                printf("Erro, deque vazia.\n");
            break;

        case 4:
            printf("\tRemover caracter do Fim da Lista ::\t");
            letra = endDequeue(&inicio, &fim);
            if ((letra) != NULL)
                printf("Valor removido: %c\n", letra);
            else
                printf("Erro, deque vazia.\n");
            break;

        case 5:
            printf("\tApresentar a Lista ::\n");
            showDeque(inicio);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
