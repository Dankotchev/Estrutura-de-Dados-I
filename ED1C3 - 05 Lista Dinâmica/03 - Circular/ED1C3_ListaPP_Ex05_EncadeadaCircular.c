/*
    EXERCÍCIO 03:
    Codifique, compile e execute um programa em Linguagem C que implemente as informações abaixo
    de uma lista simplesmente encadeada circular com nó cabeçalho formada por elementos do
    tipo inteiro positivo. Teste seu programa criando um menu com as opções de inserir,
    remover e exibir.
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

void init(CPONTO **lista)
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
        if (listaVazia(*lista))
        {
            inserir->next = inserir;
            (*lista) = inserir;
        }
        else
        {
            auxiliar = (*lista)->next;
            while (auxiliar->valor >= 0)
                auxiliar = auxiliar->next;

            auxiliar->next = inserir;
            inserir->next = *lista; // resolver exibir e voltar para aqui
        }
    }
    else
    {
        printf("\nErro na alocacao do no");
        return;
    }
}

void removerInicio(CPONTO **lista)
{
    CPONTO *auxiliar;

    if (!listaVazia(*lista))
    {
        printf("\n\tRemover Valor :: \n");
        if ((*lista) != (*lista)->next)
        {
            auxiliar = (*lista)->next;
            (*lista)->next = auxiliar->next;
            freeNode(auxiliar);
            
            
            freeNode(*lista);
            *lista = NULL;
        }
        else
            printf("Erro, lista vazia, nao e possivel remover um valor.");
    }
    else
        printf("Erro, lista vazia, nao e possivel remover um valor.");
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

    init(&lista);
    inserirFim(&lista, -3425); // Inserir o nó de cabeçalho, u valor na primeira posição que não é valido

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\tInserir Valor ::\n");
            inserirFim(&lista, lerValor());
            break;

        case 2:
            removerInicio(&lista);
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