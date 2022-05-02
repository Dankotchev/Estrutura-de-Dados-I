/*
    EXERCÍCIO 03:
    Codifique, compile e execute um programa em Linguagem C que implemente as informações
    abaixo de uma lista simplesmente encadeada circular formada por elementos do tipo
    inteiro. Teste seu programa criando um menu com as opções de inserir, remover
    e exibir.
        Operações: init; getnode, freenode, insere_fim, listar, remove_inicio

    Autor: Danilo Domingues Quirino
    Versão: 2205.02
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int valor;
    struct sCell *next;
} CPONTO;

void inicializar(CPONTO **lista)
{
    *lista = NULL;
}

CPONTO *getNode()
{
    return (CPONTO *)malloc(sizeof(CPONTO));
}

void freeNode(CPONTO *no)
{
    free(no);
}

int listaVazia(CPONTO *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void exibir(CPONTO *lista)
{
    CPONTO *exibir;

    exibir = lista->next;

    if (exibir != NULL)
    {
        do
        {
            printf("%d\t", exibir->valor);
            exibir = exibir->next;
        } while (exibir != (CPONTO *)lista->next);
    }
    else
    {
        printf("Erro, lista Vazia.\n");
    }
    printf("\n");
}

void inserirFim(CPONTO **lista, int x)
{
    CPONTO *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->valor = x;
        if (listaVazia(*lista))
        {
            inserir->next = inserir;
        }
        else
        {
            inserir->next = (*lista)->next; //Novo nó aponta para onde o ultimo nó apontava, ou seja, o primeiro nó da lista
            (*lista)->next = inserir;
        }
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return;
    }
}

int removerInicio(CPONTO ***lista)
{
    CPONTO *auxiliar;
    int valor;

    if (!listaVazia(**lista))
    {
        if ((**lista) == (**lista)->next)
        {
            valor = (**lista)->valor;
            freeNode(**lista);
            **lista = NULL;
        }
        else
        {
            auxiliar = (**lista)->next;
            valor = auxiliar->valor;
            (**lista)->next = auxiliar->next;
            freeNode(auxiliar);
        }
    }
    else
        return NULL;
    return valor;
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
    printf("\n----------\n\tOPERAÇÃO DE LISTA ENCADEADA CIRCULAR");
    printf("\nEscolha a operacao desejada.\n");
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

void removerValor(CPONTO **lista)
{
    int val;
    printf("\n\tRemover Valor :: \n");
    val = removerInicio(&lista);
    if (val != NULL)

        printf("Valor %d removido.", val);

    else

        printf("Erro, lista vazia, nenhum valor removido.");
}

int main()
{
    CPONTO *lista;
    int op;

    inicializar(&lista);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\tInserir Valor :: \nInforme o Valor: ");
            inserirFim(&lista, lerValor());
            break;

        case 2:
            removerValor(&lista);
            break;

        case 3:
            printf("\n\tApresentar a Lista ::\n");
            exibir(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}