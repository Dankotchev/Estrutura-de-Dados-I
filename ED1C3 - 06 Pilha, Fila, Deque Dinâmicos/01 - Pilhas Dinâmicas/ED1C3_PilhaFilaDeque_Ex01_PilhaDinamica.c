/*
    EXERCÍCIO 00:
    Uma pilha representa uma estrutura de dados em que os elementos só podem ser inseridos
    (empilhados) e removidos (desempilhados) do topo (início da lista). Codifique, compile e
    execute um programa que implemente as operações empilhar e desempilhar do TAD pilha usando os
    conceitos de lista linear simplesmente encadeada formada por números reais:
        a. Inserir um elemento na Pilha;
        b. Remover um elemento da Pilha
        c. Exibir elementos do Topo da Pilha.

    Autor: Danilo Domingues Quirino
    Versão: 2205.05
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    float numero;
    struct sCell *next;
} NOH;

void init(NOH **top)
{
    *top = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

void push(NOH **top, float x)
{
    NOH *inserir;
    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->numero = x;
        if (!empty(*top))
            inserir->next = *top;
        else
        	inserir->next = NULL;
        *top = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no.\n");
        return;
    }
}

float pop(NOH **top)
{
    NOH *remover;
    float x;

    if (!empty(*top))
    {
        remover = *top;
        x = remover->numero;

        *top = (*top)->next;
        freeNode(remover);
    }
    else
    {
        printf("\nErro, pilha vazia.\n");
    }
    return x;
}

float stackTop(NOH *top)
{
    if (!empty(top))
    {
        return (*top).numero;
    }
    else
    {
        printf("\nErro, pilha vazia.\n");
        return;
    }
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERACAO DE PILHAS DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valor;");
    printf("\n2 -\tRemover valor;");
    printf("\n3 -\tApresentar o Topo da Pilha;");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
    return op;
}

float lerValor()
{
    float v;
    scanf("%f", &v);
    return v;
}

int main()
{
    NOH *top;
    int op;

    init(&top);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInserir Valor :: ");
            push(&top, lerValor());
            break;

        case 2:
            printf("\tRemover Valor :: %.2f Removido\n", pop(&top));
            break;

        case 3:
            printf("\tApresentar o Topo da Pilha :: %.2f esta no Topo\n", stackTop(top));
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;

    return 0;
}
