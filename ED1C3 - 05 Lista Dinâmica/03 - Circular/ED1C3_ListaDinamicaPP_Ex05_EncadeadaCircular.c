/*
    EXERCÍCIO 05:
    Codifique, compile e execute um programa em Linguagem C que implemente as informações abaixo
    de uma lista simplesmente encadeada circular com nó cabeçalho formada por elementos do
    tipo inteiro positivo. Teste seu programa criando um menu com as opções de inserir,
    remover e exibir.
        Operações: init; getnode, freenode, insere_fim, listar, remove_inicio

    Autor: Danilo Domingues Quirino
    Versão: 2205.07
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int valor;
    struct sCell *next;
} CPONTO;

CPONTO *getNode()
{
    return (CPONTO *)malloc(sizeof(CPONTO));
}

void init(CPONTO **lista)
{
    *lista = getNode();
    if (lista != NULL)
    {
        (*lista)->valor = -3425;
        (*lista)->next = *lista;
    }
    else
        printf("\nErro na alocacao do no");
}

void freeNode(CPONTO *no)
{
    free(no);
}

void exibir(CPONTO *lista)
{
    CPONTO *exibir;

    exibir = lista->next;

    if (exibir->valor >= 0)
    {
        do
        {
            printf("%d\t", exibir->valor);
            exibir = exibir->next;
        } while (exibir->valor >= 0);
    }
    else
    {
        printf("Erro, lista Vazia.\n");
    }
    printf("\n");
}

void inserirFim(CPONTO **lista, int x)
{
    CPONTO *inserir, *auxiliar;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;

        if ((*lista)->next == *lista)
            (*lista)->next = inserir;
        else
        {
            auxiliar = (*lista)->next;
            while (auxiliar->next != *lista)
                auxiliar = auxiliar->next;
            auxiliar->next = inserir;
        }

        inserir->next = *lista;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return;
    }
}

void removerInicio(CPONTO **lista)
{
    CPONTO *remover;
    int valor;

    if ((*lista)->next != *lista)
    {
        printf("\tRemover Valor :: ");
        remover = (*lista)->next;
        valor = remover->valor;
        (*lista)->next = remover->next;
        freeNode(remover);
        printf("%d.\n", valor);
    }
    else
        printf("\tErro, lista vazia, nao e possivel remover um valor.\n");
}

int lerValor()
{
    int v;
    do
    {
        printf("Informe o Valor: ");
        scanf("%d", &v);
    } while (v < 0);
    return v;
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERAÇÃO DE LISTA ENCADEADA CIRCULAR");
    printf("\n\t\t(com cabecalho)\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir valor;");
    printf("\n2 -\tRemover valor;");
    printf("\n3 -\tApresentar Lista;");
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
    CPONTO *lista;
    int op;

    init(&lista); // Inicializa a lista, já com o nó de cabeçalho

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInserir Valor :: ");
            inserirFim(&lista, lerValor());
            break;

        case 2:
            removerInicio(&lista);
            break;

        case 3:
            printf("\tApresentar a Lista :: ");
            exibir(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
